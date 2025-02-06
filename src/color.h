#ifndef COLOR_UTILS
#define COLOR_UTILS

#include "util.h"

#define COLOR_TABLE_SIZE 16777216 // 2^24, since colors are 24-bit (0x000000 to 0xFFFFFF)

struct Color
{
  // Red
  uint8 r;

  // Green
  uint8 g;

  // Blue
  uint8 b;

  // Alpha
  uint8 a;
} typedef Color;

extern char COLOR_CODES[COLOR_TABLE_SIZE];

Color use_color(uint8 r, uint8 g, uint8 b, uint8 a);

// Function to convert a Color to a hex string
void color_to_hex(Color color, char hex[8]);

void init_color_codes();

#endif
