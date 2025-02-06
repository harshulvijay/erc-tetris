#include "../game.h"

bool rotate_piece_by_90_deg(GameState *state)
{
  Color temp_matrix[TETROMINO_SIZE][TETROMINO_SIZE]; // Temporary matrix to store the rotated piece
  Color og_copy[TETROMINO_SIZE][TETROMINO_SIZE];     // Temporary matrix to store the rotated piece

  memcpy(og_copy, state->current.visual, TETROMINO_SIZE * TETROMINO_SIZE * sizeof(Color));

  // Step 1: Copy the current piece to the temporary matrix
  memcpy(temp_matrix, state->current.visual, TETROMINO_SIZE * TETROMINO_SIZE * sizeof(Color));

  // Step 2: Rotate the temporary matrix
  rotate_matrix_counterclockwise(temp_matrix);
  memcpy(state->current.visual, temp_matrix, TETROMINO_SIZE * TETROMINO_SIZE * sizeof(Color));

  // Step 3: Check if the rotated piece is out of bounds or colliding
  if (is_out_of_bounds(state, 0, 0) || // Check bounds at the current position
      is_colliding(state, 0, 0))
  {
    memcpy(state->current.visual, og_copy, TETROMINO_SIZE * TETROMINO_SIZE * sizeof(Color));

    return false;
  }

  return true;
}

void rotate_matrix_counterclockwise(Color matrix[TETROMINO_SIZE][TETROMINO_SIZE])
{
  Color temp[TETROMINO_SIZE][TETROMINO_SIZE]; // Temporary matrix to store the rotated result

  // Step 1: Transpose the matrix
  for (int i = 0; i < TETROMINO_SIZE; i++)
  {
    for (int j = 0; j < TETROMINO_SIZE; j++)
    {
      temp[j][i] = matrix[i][j];
    }
  }

  // Step 2: Reverse the columns
  for (int i = 0; i < TETROMINO_SIZE / 2; i++)
  {
    for (int j = 0; j < TETROMINO_SIZE; j++)
    {
      Color swap = temp[i][j];
      temp[i][j] = temp[TETROMINO_SIZE - 1 - i][j];
      temp[TETROMINO_SIZE - 1 - i][j] = swap;
    }
  }

  // Step 30: Copy the rotated result back to the original matrix
  memcpy(matrix, temp, TETROMINO_SIZE * TETROMINO_SIZE * sizeof(Color));
}
