#include "../game.h"

void setup_displays(GameState *state, Display *display)
{
  clear_display_with_color(&LOCKED_DISPLAY, CLEAR_COLOR);
  state->locked_display = &LOCKED_DISPLAY;
  state->display = display;
  state->displays_set_up = true;
}

void sync_display(GameState *state)
{
  memcpy(state->display, state->locked_display, MAX_ROWS * MAX_COLS * sizeof(Color));

  for (int i = 0; i < TETROMINO_SIZE; i++)
  {
    for (int j = 0; j < TETROMINO_SIZE; j++)
    {
      if (state->current.visual[i][j].a)
      {
        int new_row = i + state->current.row_idx;
        int new_col = j + state->current.col_idx;
        Color color = state->current.visual[i][j];

        update_pixel(state->display, new_row, new_col, color);
      }
    }
  }
}
