#include "../game.h"

void clear_lines(GameState *state)
{
  for (int i = 0; i < MAX_ROWS; i++)
  {
    bool is_full = true;

    for (int j = 0; j < MAX_COLS; j++)
    {
      if (!state->locked_display->data[i][j].a)
      {
        is_full = false;
        break;
      }
    }

    if (is_full)
    {
      // Shift all rows above the cleared line down
      for (int k = i; k > 0; k--)
      {
        memcpy(state->locked_display->data[k], state->locked_display->data[k - 1], MAX_COLS * sizeof(Color));
      }

      // Clear the top row
      memset(state->locked_display->data[0], 0, MAX_COLS * sizeof(Color));
      state->score += 100;
    }
  }
}

void lock_tetromino(GameState *state)
{
  for (int i = 0; i < TETROMINO_SIZE; i++)
  {
    for (int j = 0; j < TETROMINO_SIZE; j++)
    {
      if (state->current.visual[i][j].a)
      {
        state->locked_display->data[i + state->current.row_idx][j + state->current.col_idx] = state->current.visual[i][j];
      }
    }
  }
}

void spawn_tetromino(GameState *state)
{
  int shape_i = (rand() % 7) * 1;
  const Color(*tetromino)[TETROMINO_SIZE] = TETROMINOES[shape_i];
  state->current.row_idx = 0;
  state->current.col_idx = GAME_DISPLAY_MIDDLE_COLUMN_INDEX - 2;

  memcpy(state->current.visual, tetromino, TETROMINO_SIZE * TETROMINO_SIZE * sizeof(Color));
}

MoveStatus move_tetromino(GameState *state, int d_col, int d_row)
{
  bool is_colliding_row = is_colliding(state, 0, d_row);
  bool is_colliding_col = is_colliding(state, d_col, 0);
  bool is_out_of_bounds_row = is_out_of_bounds(state, 0, d_row);
  bool is_out_of_bounds_col = is_out_of_bounds(state, d_col, 0);

  if (is_colliding_row)
    return COLLISION_ROW;

  if (is_colliding_col)
    return COLLISION_COL;

  if (is_out_of_bounds_row)
    return OUT_OF_BOUNDS_ROW;

  if (is_out_of_bounds_col)
    return OUT_OF_BOUNDS_COL;

  state->current.row_idx += d_row;
  state->current.col_idx += d_col;

  return MOVE_SUCCESS;
}
