#include "display.h"

void clear_display(Display *display)
{
  struct Color black = use_color(0, 0, 0);

  clear_display_with_color(display, black);
}

void clear_display_with_color(Display *display, Color color)
{
  for (uint y = 0; y < MAX_ROWS; y++)
  {
    for (uint x = 0; x < MAX_COLS; x++)
    {
      update_pixel(display, x, y, color);
    }
  }
}

void update_pixel(Display *display, uint x, uint y, Color new_color)
{
  if ((y >= 0 && y < MAX_COLS) && (x >= 0 && x < MAX_ROWS))
  {
    display->data[y][x] = new_color;
  }
}

Color get_pixel(Display *display, uint x, uint y)
{
  return display->data[y][x];
}
