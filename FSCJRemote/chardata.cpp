#include "chardata.h"

// A table of segment values for different characters; a HIGH value means the
// segment is lit up, while a LOW means the segment is dark; this is known as a
// common-cathode setup, where the ground (0V) side of an LED is shared between all
// the segments and the input controls the 5V side.
const PROGMEM int LED_chars[NUM_CHARS][NUM_SEGS] = {
  //  A     B     C     D     E     F     G
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH,  LOW }, // 0
  { LOW, HIGH, HIGH,  LOW,  LOW,  LOW,  LOW }, // 1
  {HIGH, HIGH,  LOW, HIGH, HIGH,  LOW, HIGH }, // 2
  {HIGH, HIGH, HIGH, HIGH,  LOW,  LOW, HIGH }, // 3
  { LOW, HIGH, HIGH,  LOW,  LOW, HIGH, HIGH }, // 4
  {HIGH,  LOW, HIGH, HIGH,  LOW, HIGH, HIGH }, // 5
  {HIGH,  LOW, HIGH, HIGH, HIGH, HIGH, HIGH }, // 6
  {HIGH, HIGH, HIGH,  LOW,  LOW,  LOW,  LOW }, // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH }, // 8
  {HIGH, HIGH, HIGH, HIGH,  LOW, HIGH, HIGH }, // 9
  {HIGH, HIGH, HIGH,  LOW, HIGH, HIGH, HIGH }, // A
  { LOW,  LOW, HIGH, HIGH, HIGH, HIGH, HIGH }, // B
  {HIGH,  LOW,  LOW, HIGH, HIGH, HIGH,  LOW }, // C
  { LOW, HIGH, HIGH, HIGH, HIGH,  LOW, HIGH }, // D
  {HIGH,  LOW,  LOW, HIGH, HIGH, HIGH, HIGH }, // E
  {HIGH,  LOW,  LOW,  LOW, HIGH, HIGH, HIGH }, // F
  { LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW }, // Blank
};

// Read a value from the table; this function allows the main program to read from
// the table without having to care if it's in variable or program memory.
int read_char_data(int digit, int seg) {
#ifdef USE_PROGMEM
  return pgm_read_word_near(&LED_chars[digit][seg]);
#else
  return LED_chars[digit][seg];
#endif
}
