#ifndef CHAR_UTILS
#define CHAR_UTILS

#include "app/gen/text.h"
#include "display.h"
#include <string.h>

// Define character matrices (5x3 for simplicity)
#define CHAR_WIDTH 8
#define CHAR_HEIGHT 8
#define SPACING 1 // Space between characters

// Color (*get_char_matrix(char c))[CHAR_WIDTH];

void scroll_text(Display *display);

#endif