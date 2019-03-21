#include "chardata.h"

// Pins for the LED digits
int LED_select1 = 2;
int LED_select2 = 4;
int LED_select3 = 5;
int LED_select4 = 6;

#define LED_SELNONE 0
#define LED_SEL1    1
#define LED_SEL2    2
#define LED_SEL3    4
#define LED_SEL4    8
#define LED_SELALL 15

// Pins for the LED segments
int LED_segA = 7;
int LED_segB = 8;
int LED_segC = 9;
int LED_segD = 10;
int LED_segE = 11;
int LED_segF = 12;
int LED_segG = 13;

// Pins for the joystick inputs
int JOY_pinX = A1;
int JOY_pinY = A0;

// Choose which digit(s) are active
void LED_SelectDigit(int digit) {
  digitalWrite(LED_select1, (digit & LED_SEL1) ? LOW : HIGH);
  digitalWrite(LED_select2, (digit & LED_SEL2) ? LOW : HIGH);
  digitalWrite(LED_select3, (digit & LED_SEL3) ? LOW : HIGH);
  digitalWrite(LED_select4, (digit & LED_SEL4) ? LOW : HIGH);
}

// Write the segment data for a digit from the table
void LED_WriteChar(int number)
{
  digitalWrite(LED_segA, read_char_data(number, 0));
  digitalWrite(LED_segB, read_char_data(number, 1));
  digitalWrite(LED_segC, read_char_data(number, 2));
  digitalWrite(LED_segD, read_char_data(number, 3));
  digitalWrite(LED_segE, read_char_data(number, 4));
  digitalWrite(LED_segF, read_char_data(number, 5));
  digitalWrite(LED_segG, read_char_data(number, 6));
}

// Write a 16-bit hexadecimal value to the LED. Since only one digit can be written
// at a time, a short delay is used between each digit so that they have time to
// light up before we move on to the next digit; selecting no digits first allow
// the next digit to be set without causing rapid flashing on the display. 
void LED_WriteShort(unsigned short number)
{
  LED_SelectDigit(LED_SELNONE);
  LED_WriteChar((number & 0xF000) >> 12);
  LED_SelectDigit(LED_SEL1);
  delay(2);   // short delay to ensure the LED receives the signal
  LED_SelectDigit(LED_SELNONE);
  LED_WriteChar((number & 0x0F00) >> 8);
  LED_SelectDigit(LED_SEL2);
  delay(2);
  LED_SelectDigit(LED_SELNONE);
  LED_WriteChar((number & 0x00F0) >> 4);
  LED_SelectDigit(LED_SEL3);
  delay(2);
  LED_SelectDigit(LED_SELNONE);
  LED_WriteChar(number & 0x000F);
  LED_SelectDigit(LED_SEL4);
  delay(14);  // last LED is dimmer, so keep it displayed longer
}

// This holds the current joystick position where X is the lower
// 8 bits and Y is the upper 8 bits. A value of approximately 127
// corresponds to the neutral position, while a value of 0 means
// the joystick is all the way to the left (X) or bottom (Y); a
// value of 255 (FF) means all the way to the right (X) or top (Y)
unsigned short joy_pos = 0;

// This is a pre-defined Arduino function; this is called once when the Arduino is
// reset or reuploaded and is used to perform one-time initialization.
void setup() {
  // Initialize the joystick pins to be inputs
  pinMode(JOY_pinX, INPUT);
  pinMode(JOY_pinY, INPUT);

  // Initialize the LED pins to be outputs
  pinMode(LED_select1, OUTPUT);
  pinMode(LED_select2, OUTPUT);
  pinMode(LED_select3, OUTPUT);
  pinMode(LED_select4, OUTPUT);
  pinMode(LED_segA, OUTPUT);
  pinMode(LED_segB, OUTPUT);
  pinMode(LED_segC, OUTPUT);
  pinMode(LED_segD, OUTPUT);
  pinMode(LED_segE, OUTPUT);
  pinMode(LED_segF, OUTPUT);
  pinMode(LED_segG, OUTPUT);

  // Ensure the LED is showing a sensible value
  LED_SelectDigit(LED_SELNONE);
  LED_WriteChar(16);
  LED_SelectDigit(LED_SELALL);
  delay(2);
  LED_SelectDigit(LED_SELNONE);

  // Turn on the serial port so we can output debugging information
  Serial.begin(9600);
}

// This is a pre-defined Arduino function. This is called repeatedly for as long as
// the Arduino has power and is used for the main loop of the program.
void loop() {
  int x, y;
  
  // Read the current joystick position
  x = analogRead(JOY_pinX);
  y = analogRead(JOY_pinY);
  joy_pos = ((x & 0x3FC) >> 2) | ((y & 0x3FC) << 6);

  // Output the current joystick position on the serial port
  Serial.print("Joystick X: ");
  Serial.print(x);
  Serial.print(" (");
  Serial.print(x/4, HEX);
  Serial.print(")\nJoystick Y: ");
  Serial.print(y);
  Serial.print(" (");
  Serial.print(y/4, HEX);
  Serial.print(")\n");
  
  // Output the current joystick position on the LED. Calling the function twice
  // allows for a total of 40 milliseconds of delay (20 per call) without causing
  // the digits to flash on the LED.
  LED_WriteShort(joy_pos);
  LED_WriteShort(joy_pos);
}
