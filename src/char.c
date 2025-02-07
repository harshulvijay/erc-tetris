#include "char.h"

Color char_A[CHAR_HEIGHT][CHAR_WIDTH] = {
    {{255, 255, 255}, {0, 0, 0}, {255, 255, 255}},
    {{255, 255, 255}, {0, 0, 0}, {255, 255, 255}},
    {{255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
    {{255, 255, 255}, {0, 0, 0}, {255, 255, 255}},
    {{255, 255, 255}, {0, 0, 0}, {255, 255, 255}}};

Color char_B[CHAR_HEIGHT][CHAR_WIDTH] = {
    {{255, 255, 255}, {255, 255, 255}, {0, 0, 0}},
    {{255, 255, 255}, {0, 0, 0}, {255, 255, 255}},
    {{255, 255, 255}, {255, 255, 255}, {0, 0, 0}},
    {{255, 255, 255}, {0, 0, 0}, {255, 255, 255}},
    {{255, 255, 255}, {255, 255, 255}, {0, 0, 0}}};

// Define more characters as needed...

Color char_SPACE[CHAR_HEIGHT][CHAR_WIDTH] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};

// Function to get the matrix for a given character
const Color (*get_char_matrix(char character))[8]
{
  switch (character)
  {
  // Lowercase letters
  case 'a':
    return TEXT_COLORED_A;
  case 'b':
    return TEXT_COLORED_B;
  case 'c':
    return TEXT_COLORED_C;
  case 'd':
    return TEXT_COLORED_D;
  case 'e':
    return TEXT_COLORED_E;
  case 'f':
    return TEXT_COLORED_F;
  case 'g':
    return TEXT_COLORED_G;
  case 'h':
    return TEXT_COLORED_H;
  case 'i':
    return TEXT_COLORED_I;
  case 'j':
    return TEXT_COLORED_J;
  case 'k':
    return TEXT_COLORED_K;
  case 'l':
    return TEXT_COLORED_L;
  case 'm':
    return TEXT_COLORED_M;
  case 'n':
    return TEXT_COLORED_N;
  case 'o':
    return TEXT_COLORED_O;
  case 'p':
    return TEXT_COLORED_P;
  case 'q':
    return TEXT_COLORED_Q;
  case 'r':
    return TEXT_COLORED_R;
  case 's':
    return TEXT_COLORED_S;
  case 't':
    return TEXT_COLORED_T;
  case 'u':
    return TEXT_COLORED_U;
  case 'v':
    return TEXT_COLORED_V;
  case 'w':
    return TEXT_COLORED_W;
  case 'x':
    return TEXT_COLORED_X;
  case 'y':
    return TEXT_COLORED_Y;
  case 'z':
    return TEXT_COLORED_Z;

  // Uppercase letters
  case 'A':
    return TEXT_COLORED_UC_A;
  case 'B':
    return TEXT_COLORED_UC_B;
  case 'C':
    return TEXT_COLORED_UC_C;
  case 'D':
    return TEXT_COLORED_UC_D;
  case 'E':
    return TEXT_COLORED_UC_E;
  case 'F':
    return TEXT_COLORED_UC_F;
  case 'G':
    return TEXT_COLORED_UC_G;
  case 'H':
    return TEXT_COLORED_UC_H;
  case 'I':
    return TEXT_COLORED_UC_I;
  case 'J':
    return TEXT_COLORED_UC_J;
  case 'K':
    return TEXT_COLORED_UC_K;
  case 'L':
    return TEXT_COLORED_UC_L;
  case 'M':
    return TEXT_COLORED_UC_M;
  case 'N':
    return TEXT_COLORED_UC_N;
  case 'O':
    return TEXT_COLORED_UC_O;
  case 'P':
    return TEXT_COLORED_UC_P;
  case 'Q':
    return TEXT_COLORED_UC_Q;
  case 'R':
    return TEXT_COLORED_UC_R;
  case 'S':
    return TEXT_COLORED_UC_S;
  case 'T':
    return TEXT_COLORED_UC_T;
  case 'U':
    return TEXT_COLORED_UC_U;
  case 'V':
    return TEXT_COLORED_UC_V;
  case 'W':
    return TEXT_COLORED_UC_W;
  case 'X':
    return TEXT_COLORED_UC_X;
  case 'Y':
    return TEXT_COLORED_UC_Y;
  case 'Z':
    return TEXT_COLORED_UC_Z;

  // Digits
  case '0':
    return TEXT_COLORED_NUM_0;
  case '1':
    return TEXT_COLORED_NUM_1;
  case '2':
    return TEXT_COLORED_NUM_2;
  case '3':
    return TEXT_COLORED_NUM_3;
  case '4':
    return TEXT_COLORED_NUM_4;
  case '5':
    return TEXT_COLORED_NUM_5;
  case '6':
    return TEXT_COLORED_NUM_6;
  case '7':
    return TEXT_COLORED_NUM_7;
  case '8':
    return TEXT_COLORED_NUM_8;
  case '9':
    return TEXT_COLORED_NUM_9;

  // Special characters
  case '!':
    return TEXT_COLORED_EXCL;
  case '"':
    return TEXT_COLORED_QUOTE;
  case '#':
    return TEXT_COLORED_HASH;
  case '$':
    return TEXT_COLORED_DOLLAR;
  case '%':
    return TEXT_COLORED_PERCENT;
  case '&':
    return TEXT_COLORED_AMP;
  case '\'':
    return TEXT_COLORED_APOSTROPHE;
  case '(':
    return TEXT_COLORED_LPAREN;
  case ')':
    return TEXT_COLORED_RPAREN;
  case '*':
    return TEXT_COLORED_ASTERISK;
  case '+':
    return TEXT_COLORED_PLUS;
  case ',':
    return TEXT_COLORED_COMMA;
  case '-':
    return TEXT_COLORED_MINUS;
  case '.':
    return TEXT_COLORED_DOT;
  case '/':
    return TEXT_COLORED_SLASH;
  case ':':
    return TEXT_COLORED_COLON;
  case ';':
    return TEXT_COLORED_SEMICOLON;
  case '<':
    return TEXT_COLORED_LT;
  case '=':
    return TEXT_COLORED_EQUAL;
  case '>':
    return TEXT_COLORED_GT;
  // case '?':
  //   return TEXT_COLORED_Q;
  case '@':
    return TEXT_COLORED_AT;
  case '[':
    return TEXT_COLORED_LBRACK;
  case '\\':
    return TEXT_COLORED_BACKSLASH;
  case ']':
    return TEXT_COLORED_RBRACK;
  case '^':
    return TEXT_COLORED_CARET;
  case '_':
    return TEXT_COLORED_UNDERSCORE;
  case '`':
    return TEXT_COLORED_BACKTICK;
  case '{':
    return TEXT_COLORED_LBRACE;
  case '|':
    return TEXT_COLORED_PIPE;
  case '}':
    return TEXT_COLORED_RBRACE;
  case '~':
    return TEXT_COLORED_TILDE;

  // Space character
  case ' ':
    return TEXT_COLORED_SPACE;

  // Default case for unknown characters
  default:
    return TEXT_COLORED_SPACE;
  }
}

// Global variables for scrolling
char text[] = "a b c"; // Text to scroll
int text_length = -1;
int scroll_offset = 0;

// Function to update the display with the scrolled text
void scroll_text(Display *display)
{
  Color CLEAR_COLOR = {.r = 0, .g = 0, .b = 0, .a = 0};

  if (text_length < 0)
  {
    text_length = strlen(text);
  }

  // Clear the display
  clear_display_with_color(display, CLEAR_COLOR);

  // Draw the text with the current scroll offset
  for (int i = 0; i < 40; i++)
  {
    int char_index = (scroll_offset + i) / (CHAR_WIDTH + SPACING);
    int col_in_char = (scroll_offset + i) % (CHAR_WIDTH + SPACING);

    if (col_in_char < CHAR_WIDTH)
    {
      char current_char = text[char_index % text_length];
      const Color(*char_matrix)[CHAR_WIDTH] = get_char_matrix(current_char);

      for (int row = 0; row < CHAR_HEIGHT; row++)
      {
        display->data[row][i] = char_matrix[row][col_in_char];
      }
    }
  }

  // Update the scroll offset
  scroll_offset = (scroll_offset + 1) % (text_length * (CHAR_WIDTH + SPACING));
}