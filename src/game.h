#ifndef GAME_CORE
#define GAME_CORE

#include "app/gen/screens.h"
#include "app/gen/tetrominoes.h"
#include "app/gen/text.h"
#include "display.h"
#include "gtk.h"
#include "util.h"
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GAME_DISPLAY_MIDDLE_COLUMN_INDEX (int)(MAX_COLS / 2)
#define TETROMINO_SIZE TETROMINOES_HEIGHT

typedef enum
{
  MOVE_SUCCESS,
  COLLISION_ROW,
  COLLISION_COL,
  OUT_OF_BOUNDS_ROW,
  OUT_OF_BOUNDS_COL,
} MoveStatus;

typedef enum
{
  SCREEN_TYPE_NONE,
  SCREEN_TYPE_START,
  SCREEN_TYPE_END,
} ScreenType;

typedef struct
{
  int row_idx, col_idx;
  Color visual[TETROMINO_SIZE][TETROMINO_SIZE];
} Tetromino;

typedef struct
{
  Display *display;
  Display *locked_display;
  Tetromino current;
  int score;
  bool game_over;
  bool initialized;
  bool displays_set_up;
  ScreenType current_screen;
} GameState;

extern const Color CLEAR_COLOR;
extern const Color (*const TETROMINOES[])[TETROMINO_SIZE];
extern GameState GAME_STATE;
extern Display LOCKED_DISPLAY;

void render_end_screen(GameState *state);
void render_start_screen(GameState *state);

void clear_lines(GameState *state);
void lock_tetromino(GameState *state);
void spawn_tetromino(GameState *state);
MoveStatus move_tetromino(GameState *state, int d_col, int d_row);

bool is_colliding(const GameState *state, const int d_col, const int d_row);
bool is_out_of_bounds(const GameState *state, const int d_col, const int d_row);

bool rotate_piece_by_90_deg(GameState *state);
void rotate_matrix_counterclockwise(Color matrix[TETROMINO_SIZE][TETROMINO_SIZE]);

void setup_displays(GameState *state, Display *display);
void sync_display(GameState *state);

bool is_game_over(const GameState *state, const MoveStatus move_result);
void game_tick(Display *display);
void init_game(GameState *state);
void on_game_over(GameState *state);
void parse_input(GameState *state);
void start_game();

#endif
