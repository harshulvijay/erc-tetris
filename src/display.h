#ifndef DISPLAY_UTILS
#define DISPLAY_UTILS

#include "color.h"
#include "util.h"

#define MAX_ROWS 40
#define MAX_COLS 20

struct Display
{
  Color data[MAX_ROWS][MAX_COLS];
} typedef Display;

void clear_display(Display *display);
void clear_display_with_color(Display *display, Color color);

Color get_pixel(Display *display, uint row, uint col);

void update_pixel(Display *display, uint row, uint col, Color new_color);

#endif
