#ifndef COLOR_UTILS
#define COLOR_UTILS

#include "util.h"

struct Color
{
  // Red
  uint8 r;

  // Green
  uint8 g;

  // Blue
  uint8 b;
} typedef Color;

Color use_color(uint8 r, uint8 g, uint8 b);

#endif
