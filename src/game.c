#include "game.h"

void wooo(Display *display)
{
  clear_display(display);

  print_matrix_to_file("oh.log", MAX_ROWS, MAX_COLS, display->data);

  // int i = 0;
  // while (true)
  // {
  //   printf("%x;", i);
  //   i++;
  // }
};
