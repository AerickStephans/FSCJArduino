#include <TVout.h>
#include <fontALL.h>
#include "schematic.h"
#include "TVOlogo.h"
#include "logo.h"

TVout TV;

int zOff = 150;
int xOff = 0;
int yOff = 0;
int cSize = 50;
int view_plane = 64;
float angle = PI/60;

float cube3d[8][3] = {
  {xOff - cSize,yOff + cSize,zOff - cSize},
  {xOff + cSize,yOff + cSize,zOff - cSize},
  {xOff - cSize,yOff - cSize,zOff - cSize},
  {xOff + cSize,yOff - cSize,zOff - cSize},
  {xOff - cSize,yOff + cSize,zOff + cSize},
  {xOff + cSize,yOff + cSize,zOff + cSize},
  {xOff - cSize,yOff - cSize,zOff + cSize},
  {xOff + cSize,yOff - cSize,zOff + cSize}
};
unsigned char cube2d[8][2];

void main_loop() {
  TV.clear_screen();
  TV.select_font(font6x8);
  intro();
  TV.println("This is a modified version");
  TV.delay(1000);
  TV.println("of the DemoNTSC demo code");
  TV.delay(1000);
  TV.println("included in David Mellis'");
  TV.delay(1000);
  TV.println("TVoutlibrary running on an");
  TV.delay(1000);
  TV.println("Arduino Mega 2560 micro-.");
  TV.delay(1000);
  TV.println("controller. For more about");
  TV.delay(1000);
  TV.println("this library, please visit");
  TV.delay(1000);
  TV.println("https://playground.arduino.cc/Main/TVout\n");
  TV.delay(3000);
  TV.clear_screen();
  TV.println("I generate NTSC signals,");
  TV.delay(1000);
  TV.println("such as the yellow cables");
  TV.delay(1000);
  TV.println("for TVs used in the USA,");
  TV.delay(1000);
  TV.println("by using interrupts.\n");
  TV.delay(1000);
  TV.println("My schematic is:");
  TV.delay(1000);
  TV.bitmap(0,56,schematic);
  TV.delay(10000);
  TV.clear_screen();
  TV.println("Lets see what I can do!\n");
  TV.delay(2000);
  
  //fonts
  //TV.clear_screen();
  TV.println("Multiple fonts:");
  TV.select_font(font4x6);
  TV.println("4x6 font FONT");
  TV.select_font(font6x8);
  TV.println("6x8 font FONT");
  TV.select_font(font8x8);
  TV.println("8x8 font FONT");
  TV.select_font(font6x8);
  TV.delay(2000);
  
  //TV.clear_screen();
  TV.print("Draw Basic Shapes");
  TV.delay(2000);
  
  //circles
  TV.clear_screen();
  TV.draw_circle(TV.hres()/2,TV.vres()/2,TV.vres()/3,WHITE);
  TV.delay(500);
  TV.draw_circle(TV.hres()/2,TV.vres()/2,TV.vres()/2,WHITE,INVERT);
  TV.delay(2000);
  
  //rectangles and lines
  TV.clear_screen();
  TV.draw_rect(20,20,120,104,WHITE);
  TV.delay(500);
  TV.draw_rect(10,10,140,124,WHITE,INVERT);
  TV.delay(500);
  TV.draw_line(80,10,80,134,INVERT);
  TV.draw_line(10,72,150,72,INVERT);
  TV.delay(500);
  TV.draw_line(10,10,150,134,INVERT);
  TV.draw_line(10,134,150,10,INVERT);
  TV.delay(2000);
  
  //random cube forever.
  TV.clear_screen();
  TV.print(16,40,"Random Cube");
  TV.print(28,48,"Rotation");
  TV.delay(2000);
  TV.clear_screen();
  
  randomSeed(analogRead(0));
}

void cube_loop() {
  int rsteps = random(10,60);
  switch(random(6)) {
    case 0:
      for (int i = 0; i < rsteps; i++) {
        zrotate(angle);
        printcube();
      }
      break;
    case 1:
      for (int i = 0; i < rsteps; i++) {
        zrotate(2*PI - angle);
        printcube();
      }
      break;
    case 2:
      for (int i = 0; i < rsteps; i++) {
        xrotate(angle);
        printcube();
      }
      break;
    case 3:
      for (int i = 0; i < rsteps; i++) {
        xrotate(2*PI - angle);
        printcube();
      }
      break;
    case 4:
      for (int i = 0; i < rsteps; i++) {
        yrotate(angle);
        printcube();
      }
      break;
    case 5:
      for (int i = 0; i < rsteps; i++) {
        yrotate(2*PI - angle);
        printcube();
      }
      break;
  }
}

void setup() {
  TV.begin(NTSC,160,144);
}

void loop() {
  char numbers[4] = { 0, 0, 0, 0 };
  main_loop();
  for(int i = 0; i < 300; i++)
  {
    numbers[0] = (i / 100) + '0';
    numbers[1] = ((i / 10) % 10) + '0';
    numbers[1] = (i % 10) + '0';

    cube_loop();

    TV.println(0, 0, numbers);
  }
}

void intro() {
unsigned char w,l,wb;
  int index;
  w = pgm_read_byte(logo_image);
  l = pgm_read_byte(logo_image+1);
  if (w&7)
    wb = w/8 + 1;
  else
    wb = w/8;
  index = wb*(l-1) + 2;
  for ( unsigned char i = 1; i < l; i++ ) {
    TV.bitmap((TV.hres() - w)/2,0,logo_image,index,w,i);
    index-= wb;
    TV.delay(50);
  }
  for (unsigned char i = 0; i < (TV.vres() - l)/2; i++) {
    TV.bitmap((TV.hres() - w)/2,i,logo_image);
    TV.delay(50);
  }
  TV.delay(3000);
  TV.clear_screen();
}

void printcube() {
  TV.delay_frame(1);
  clear_cube();
  //calculate 2d points
  for(byte i = 0; i < 8; i++) {
    cube2d[i][0] = (unsigned char)((cube3d[i][0] * view_plane / cube3d[i][2]) + (TV.hres()/2));
    cube2d[i][1] = (unsigned char)((cube3d[i][1] * view_plane / cube3d[i][2]) + (TV.vres()/2));
  }
  //TV.clear_screen();
  draw_cube();
}

void zrotate(float q) {
  float tx,ty,temp;
  for(byte i = 0; i < 8; i++) {
    tx = cube3d[i][0] - xOff;
    ty = cube3d[i][1] - yOff;
    temp = tx * cos(q) - ty * sin(q);
    ty = tx * sin(q) + ty * cos(q);
    tx = temp;
    cube3d[i][0] = tx + xOff;
    cube3d[i][1] = ty + yOff;
  }
}

void yrotate(float q) {
  float tx,tz,temp;
  for(byte i = 0; i < 8; i++) {
    tx = cube3d[i][0] - xOff;
    tz = cube3d[i][2] - zOff;
    temp = tz * cos(q) - tx * sin(q);
    tx = tz * sin(q) + tx * cos(q);
    tz = temp;
    cube3d[i][0] = tx + xOff;
    cube3d[i][2] = tz + zOff;
  }
}

void xrotate(float q) {
  float ty,tz,temp;
  for(byte i = 0; i < 8; i++) {
    ty = cube3d[i][1] - yOff;
    tz = cube3d[i][2] - zOff;
    temp = ty * cos(q) - tz * sin(q);
    tz = ty * sin(q) + tz * cos(q);
    ty = temp;
    cube3d[i][1] = ty + yOff;
    cube3d[i][2] = tz + zOff;
  }
}

void draw_cube() {
  TV.draw_line(cube2d[0][0],cube2d[0][1],cube2d[1][0],cube2d[1][1],WHITE);
  TV.draw_line(cube2d[0][0],cube2d[0][1],cube2d[2][0],cube2d[2][1],WHITE);
  TV.draw_line(cube2d[0][0],cube2d[0][1],cube2d[4][0],cube2d[4][1],WHITE);
  TV.draw_line(cube2d[1][0],cube2d[1][1],cube2d[5][0],cube2d[5][1],WHITE);
  TV.draw_line(cube2d[1][0],cube2d[1][1],cube2d[3][0],cube2d[3][1],WHITE);
  TV.draw_line(cube2d[2][0],cube2d[2][1],cube2d[6][0],cube2d[6][1],WHITE);
  TV.draw_line(cube2d[2][0],cube2d[2][1],cube2d[3][0],cube2d[3][1],WHITE);
  TV.draw_line(cube2d[4][0],cube2d[4][1],cube2d[6][0],cube2d[6][1],WHITE);
  TV.draw_line(cube2d[4][0],cube2d[4][1],cube2d[5][0],cube2d[5][1],WHITE);
  TV.draw_line(cube2d[7][0],cube2d[7][1],cube2d[6][0],cube2d[6][1],WHITE);
  TV.draw_line(cube2d[7][0],cube2d[7][1],cube2d[3][0],cube2d[3][1],WHITE);
  TV.draw_line(cube2d[7][0],cube2d[7][1],cube2d[5][0],cube2d[5][1],WHITE);
}

void clear_cube() {
  TV.draw_line(cube2d[0][0],cube2d[0][1],cube2d[1][0],cube2d[1][1],BLACK);
  TV.draw_line(cube2d[0][0],cube2d[0][1],cube2d[2][0],cube2d[2][1],BLACK);
  TV.draw_line(cube2d[0][0],cube2d[0][1],cube2d[4][0],cube2d[4][1],BLACK);
  TV.draw_line(cube2d[1][0],cube2d[1][1],cube2d[5][0],cube2d[5][1],BLACK);
  TV.draw_line(cube2d[1][0],cube2d[1][1],cube2d[3][0],cube2d[3][1],BLACK);
  TV.draw_line(cube2d[2][0],cube2d[2][1],cube2d[6][0],cube2d[6][1],BLACK);
  TV.draw_line(cube2d[2][0],cube2d[2][1],cube2d[3][0],cube2d[3][1],BLACK);
  TV.draw_line(cube2d[4][0],cube2d[4][1],cube2d[6][0],cube2d[6][1],BLACK);
  TV.draw_line(cube2d[4][0],cube2d[4][1],cube2d[5][0],cube2d[5][1],BLACK);
  TV.draw_line(cube2d[7][0],cube2d[7][1],cube2d[6][0],cube2d[6][1],BLACK);
  TV.draw_line(cube2d[7][0],cube2d[7][1],cube2d[3][0],cube2d[3][1],BLACK);
  TV.draw_line(cube2d[7][0],cube2d[7][1],cube2d[5][0],cube2d[5][1],BLACK);
}
