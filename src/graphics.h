#ifndef GRAPHICS_UTILS
#define GRAPHICS_UTILS

#include "game.h"
#include "util.h"
#include <gtk/gtk.h>
#include <stdbool.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

typedef struct
{
  uint frame_number;
} FrameMetadata;

// FPS the game loop will run at
#define TARGET_FPS 30

#define TARGET_FRAME_TIME (1000.0 / TARGET_FPS)

void init_graphics_loop(Display *display);

void update_graphics(Display *display, FrameMetadata *frame_metadata);

#endif
