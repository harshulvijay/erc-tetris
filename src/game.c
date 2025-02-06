#include "game.h"

GameState GAME_STATE = {
    .game_over = true,
    .initialized = false,
    .score = 0,
    .current_screen = SCREEN_TYPE_NONE,
};
Display LOCKED_DISPLAY = {0};
const Color CLEAR_COLOR = {.r = 0, .g = 0, .b = 0, .a = 0};
const Color (*const TETROMINOES[])[8] = {
    TETROMINOES_COLORED_I,
    TETROMINOES_COLORED_J,
    TETROMINOES_COLORED_L,
    TETROMINOES_COLORED_O,
    TETROMINOES_COLORED_S,
    TETROMINOES_COLORED_T,
    TETROMINOES_COLORED_Z,
};

bool is_game_over(const GameState *state, const MoveStatus move_result)
{
  return move_result == COLLISION_ROW && GAME_STATE.current.row_idx == 0;
}

void parse_input(GameState *state)
{
  if (keys.up)
  {
    rotate_piece_by_90_deg(state);
  }
  if (keys.down)
  {
    move_tetromino(state, 0, 3);
  }
  if (keys.left)
  {
    move_tetromino(state, -2, 0);
  }
  if (keys.right)
  {
    move_tetromino(state, 2, 0);
  }
}

void start_game(GameState *state)
{
  if (state->current_screen == SCREEN_TYPE_NONE)
  {
    render_start_screen(state);
  }
  if (state->current_screen == SCREEN_TYPE_END)
  {
    render_end_screen(state);
  }

  if (keys.space)
  {
    clear_display_with_color(&LOCKED_DISPLAY, CLEAR_COLOR);
    state->game_over = false;
    state->current_screen = SCREEN_TYPE_NONE;
  }
}

void init_game(GameState *state)
{
  state->game_over = false;
  state->initialized = true;
  state->score = 0;

  spawn_tetromino(state);
}

void on_game_over(GameState *state)
{
  printf("Game over! Final score: %d\n", GAME_STATE.score);

  state->game_over = true;
  state->initialized = false;
  state->score = 0;
  state->current_screen = SCREEN_TYPE_NONE;

  clear_display_with_color(state->display, CLEAR_COLOR);
  state->current_screen = SCREEN_TYPE_END;
}

int current_color_index = 0;

Color COLORS_X[] = {
    // Initialize the colorCodes array with default values
    {.r = 255, .g = 0, .b = 0, .a = 255},     // Red
    {.r = 0, .g = 255, .b = 0, .a = 255},     // Green
    {.r = 0, .g = 0, .b = 255, .a = 255},     // Blue
    {.r = 255, .g = 255, .b = 0, .a = 255},   // Yellow
    {.r = 0, .g = 255, .b = 255, .a = 255},   // Cyan
    {.r = 255, .g = 0, .b = 255, .a = 255},   // Magenta
    {.r = 255, .g = 255, .b = 255, .a = 255}, // White
    {.r = 51, .g = 51, .b = 51, .a = 255},    // Dim Gray
    {.r = 255, .g = 165, .b = 0, .a = 255},   // Orange
    {.r = 127, .g = 0, .b = 255, .a = 255},   // Violet
    {.r = 75, .g = 0, .b = 130, .a = 255},    // Indigo
};

void game_tick(Display *display)
{
  Color color = COLORS_X[current_color_index];
  clear_display_with_color(display, color);
  current_color_index++;

  if (current_color_index >= 11)
  {
    current_color_index = 0;
  }

  // if (!GAME_STATE.displays_set_up)
  // {
  //   setup_displays(&GAME_STATE, display);
  // }

  // if (GAME_STATE.game_over)
  // {
  //   start_game(&GAME_STATE);
  // }
  // else
  // {
  //   parse_input(&GAME_STATE);

  //   if (!GAME_STATE.initialized)
  //   {
  //     init_game(&GAME_STATE);
  //     spawn_tetromino(&GAME_STATE);
  //   }
  //   else
  //   {
  //     int move_result = move_tetromino(&GAME_STATE, 0, 1);

  //     if (move_result == OUT_OF_BOUNDS_ROW || move_result == COLLISION_ROW)
  //     {

  //       lock_tetromino(&GAME_STATE);
  //       if (is_game_over(&GAME_STATE, move_result))
  //       {
  //         // the piece is colliding an already exisiting piece
  //         // so the game is over
  //         on_game_over(&GAME_STATE);
  //       }
  //       else
  //       {
  //         spawn_tetromino(&GAME_STATE);
  //       }
  //     }

  //     clear_lines(&GAME_STATE);
  //   }

  //   sync_display(&GAME_STATE);
  // }
}
