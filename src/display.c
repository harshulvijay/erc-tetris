#include "display.h"

void clear_display(Display *display)
{
  struct Color black = use_color(0, 0, 0, 255);

  clear_display_with_color(display, black);
}

void clear_display_with_color(Display *display, Color color)
{
  for (uint row = 0; row < MAX_ROWS; row++)
  {
    for (uint col = 0; col < MAX_COLS; col++)
    {
      update_pixel(display, row, col, color);
    }
  }
}

void update_pixel(Display *display, uint row, uint col, Color new_color)
{
  if ((col >= 0 && col < MAX_COLS) && (row >= 0 && row < MAX_ROWS))
  {
    display->data[row][col] = new_color;
  }
}

Color get_pixel(Display *display, uint row, uint col)
{
  return display->data[row][col];
}
