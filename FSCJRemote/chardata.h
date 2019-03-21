#ifndef CHARDATA_H
#define CHARDARA_H

// By commenting this out or not, we choose whether to keep our character table in
// RAM or in ROM; since the Arduino has much more ROM than RAM and the table is
// unchanging, it's better to keep it in ROM.
#define USE_PROGMEM

#include <Arduino.h>
#include <avr/pgmspace.h>

// If we're keeping the table in RAM, the keyword that specifies that property is
// disabled here.
#ifndef USE_PROGMEM
#undef PROGMEM
#define PROGMEM
#endif

#define NUM_CHARS 17
#define NUM_SEGS  7

extern const int LED_chars[NUM_CHARS][NUM_SEGS];
int read_char_data(int digit, int seg);

#endif
