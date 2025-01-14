#ifndef GRAPHICS_UTILS
#define GRAPHICS_UTILS

#include "game.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <gtk/gtk.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

// FPS the game loop will run at
#define TARGET_FPS 30

#define TARGET_FRAME_TIME (1000.0 / TARGET_FPS)

void init_graphics_loop(Display *display);

void update_graphics(int frame_number, Display *display);

#endif
