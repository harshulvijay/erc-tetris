#include "../game.h"

bool is_colliding(const GameState *state, const int d_col, const int d_row)
{
  for (int i_row = 0; i_row < TETROMINO_SIZE; i_row++)
  {
    for (int i_col = 0; i_col < TETROMINO_SIZE; i_col++)
    {
      if (!state->current.visual[i_row][i_col].a)
        continue;

      int new_row_idx = state->current.row_idx + i_row + d_row;
      int new_col_idx = state->current.col_idx + i_col + d_col;

      if (state->locked_display->data[new_row_idx][new_col_idx].a)
      {
        return true;
      }
    }
  }

  return false;
}

bool is_out_of_bounds(const GameState *state, const int d_col, const int d_row)
{
  for (int i_row = 0; i_row < TETROMINO_SIZE; i_row++)
  {
    for (int i_col = 0; i_col < TETROMINO_SIZE; i_col++)
    {
      if (!state->current.visual[i_row][i_col].a)
        continue;

      int new_row_idx = state->current.row_idx + i_row + d_row;
      int new_col_idx = state->current.col_idx + i_col + d_col;

      if (new_row_idx < 0 || new_col_idx < 0)
      {
        return true;
      }

      if (new_row_idx >= MAX_ROWS || new_col_idx >= MAX_COLS)
      {
        return true;
      }
    }
  }

  return false;
}
