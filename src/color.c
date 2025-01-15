#include "color.h"
#include <stdio.h>

Color use_color(uint8 r, uint8 g, uint8 b)
{
  Color color;

  color.r = r;
  color.g = g;
  color.b = b;

  return color;
};
