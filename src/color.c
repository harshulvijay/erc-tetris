#include "color.h"
#include <stdio.h>

char COLOR_CODES[COLOR_TABLE_SIZE] = {'w'};

void init_color_codes()
{
  // Initialize the COLOR_CODES array with default values
  COLOR_CODES[0xFF0000] = 'r'; // Red
  COLOR_CODES[0x00FF00] = 'g'; // Green
  COLOR_CODES[0x0000FF] = 'b'; // Blue
  COLOR_CODES[0xFFFF00] = 'y'; // Yellow
  COLOR_CODES[0x00FFFF] = 'c'; // Cyan
  COLOR_CODES[0xFF00FF] = 'm'; // Magenta
  COLOR_CODES[0XFFFFFF] = 'w'; // White
  COLOR_CODES[0x333333] = 'd'; // Dim Gray
  COLOR_CODES[0xFFA500] = 'o'; // Orange
  COLOR_CODES[0x8CFFFB] = 'v'; // Violet
  COLOR_CODES[0x4B0082] = 'i'; // Indigo
  COLOR_CODES[0x7F00FF] = 'v'; // Violet
  // COLOR_CODES[0x000000] = 'w'; // Black
  // COLOR_CODES[0x585858] = 'v'; // Violet
}

// Function to convert a Color to a hex string
void color_to_hex(Color color, char hex[8])
{
  // Format the color into the provided hex buffer
  snprintf(hex, 8, "%02X%02X%02X", color.r, color.g, color.b);
}

Color use_color(uint8 r, uint8 g, uint8 b, uint8 a)
{
  Color color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;

  return color;
};
