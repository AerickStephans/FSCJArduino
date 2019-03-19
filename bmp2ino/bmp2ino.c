/********************************
		 bmp2ino
Converts a Windows monochrome
bitmap to a C array, starting
with height and width, for use
with the TVout library for the
Arduino series of microcontrollers.
By Joseph Fortune and Aerick Stephans
3/18/2019
********************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#pragma pack(1);

struct BMP_File_Header
{
	uint8_t bfType[2];
	uint32_t bfSize;
	uint32_t bfReserved;
	uint32_t bfOffBits;
};

struct BMP_Image_Header
{
	uint32_t biSize;
	uint32_t biWidth;
	uint32_t biHeight;
	uint16_t biPlanes;
	uint16_t biBitCount;
};

int divideRoundUp(int num, int divisor)
{
	int i, quotient;
	for(i = num, quotient = 0; i > 0; i -= divisor, quotient++);
	return quotient;
}

int main(int argc, char* argv[])
{
	struct BMP_File_Header fHeader;
	struct BMP_Image_Header iHeader;
	int pixelsSize, imageSize, scanLineWidth, padding;
	uint8_t *pixels = NULL;
	FILE *fp = NULL;
	int i, j;

	if ( argc != 2 )
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0] );
		return 0;
	}

	// Open file
	fp = fopen(argv[1], "rb");
	if ( fp == NULL )
	{
		fprintf(stderr, "Error opening file\n");
		return 0;
	}

	// Read file header
	if (fread(&fHeader , sizeof(struct BMP_File_Header), 1, fp) < 1)
	{
		fprintf(stderr, "Error reading file\n");
		return 0;
	}

	// Validate file format
	if ( !(fHeader.bfType[0] == 'B') && (fHeader.bfType[1]) == 'M')
	{
		fprintf(stderr, "Invalid bitmap file.\n");
		return 0;
	}

	// Read image header
	if (fread(&iHeader , sizeof(struct BMP_Image_Header), 1, fp) < 1)
	{
		fprintf(stderr, "Error reading bmp image header\n");
		return 0;
	}

	fprintf(stderr, "\n%s - %d x %d - %d bit(s) per pixel\n\n", argv[1], iHeader.biWidth, iHeader.biHeight, iHeader.biBitCount);

	// Verifty the bitmap is 1 bit per pixel
	if (iHeader.biBitCount != 1)
	{
		fprintf(stderr, "Error: image must monochrome (1 bit per pixel)\n");
		return 0;
	}

	// Prepare some information for the pixels
	imageSize = divideRoundUp(iHeader.biHeight * iHeader.biWidth, 8);
	//scanLineWidth = ((iHeader.biWidth / 8) / 4 + 1) * 4;
	scanLineWidth = ((iHeader.biWidth + 3) / 8);
	padding = scanLineWidth % 4;




	// Get pixel data
	pixelsSize = iHeader.biHeight * scanLineWidth;
	pixels = (uint8_t *)malloc(pixelsSize + 1);
	if(!pixels)
	{
		fclose(fp);
		fprintf(stderr, "Error: out of memory!");
		return 0;
	}
	
	fprintf(stderr, "Image Offset: %d\n", fHeader.bfOffBits);
	fprintf(stderr, "Reading size: %d\n", pixelsSize);	
	fprintf(stderr, "ScanLineWidth: %d\n", scanLineWidth);
	fprintf(stderr, "Padding: %d\n", padding);
	
	fseek(fp, fHeader.bfOffBits, SEEK_SET);
	i = ftell(fp);
	j = fread(pixels, 1, pixelsSize, fp);
	fprintf(stderr, "Read %d bytes of pixel data from offset %d\n", j, i);
	if (j < pixelsSize)
	{
		free(pixels);
		fprintf(stderr, "Error reading pixel data\n");
		return 0;
	}

	// Print the data as a C array
	printf("PROGMEM const unsigned char image[] = { %d, %d,\n", iHeader.biWidth, iHeader.biHeight);
	for (i = 0, j = 0; i < pixelsSize; i++)
	{
			
		// Disregard null padding
		if ( (padding > 0) && !((i + padding) % scanLineWidth ))
			i += padding - 1;

		else
		{
			printf("0x%02x, ", pixels[((iHeader.biHeight - 1 - (i/scanLineWidth))*scanLineWidth) + (i%scanLineWidth)]);
			fprintf(stderr, "%d, ", ((iHeader.biHeight - 1 - (i/scanLineWidth))*scanLineWidth) + (i%scanLineWidth));
			// New line
			j++;
			if ( j >= 10 ) // Line width
			{
				printf("\n");
				fprintf(stderr, "\n");
				j = 0;
			}
		}
		//printf("(j: %d) ", j);
		
	}
	printf("};\n");
	
	free(pixels);
	fclose(fp);
	
	return 0;
}
