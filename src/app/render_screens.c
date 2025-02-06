#include "../game.h"

void render_end_screen(GameState *state)
{
  memcpy(state->display->data, SCREENS_COLORED_BGEND, MAX_ROWS * MAX_COLS * sizeof(Color));
  state->current_screen = SCREEN_TYPE_END;
}

void render_start_screen(GameState *state)
{
  memcpy(state->display->data, SCREENS_COLORED_BGSTART, MAX_ROWS * MAX_COLS * sizeof(Color));
  state->current_screen = SCREEN_TYPE_START;
}
