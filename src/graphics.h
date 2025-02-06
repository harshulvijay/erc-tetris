#ifndef GRAPHICS_UTILS
#define GRAPHICS_UTILS

#include "comms.h"
#include "game.h"
#include "util.h"
#include <gdk/gdkkeysyms.h> // For key symbols like GDK_KEY_W, GDK_KEY_Up, etc.
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
#define TARGET_FPS 0.20
#define TARGET_FRAME_TIME (1000.0 / TARGET_FPS)

void init_graphics_loop(Display *display, ESPConnection *connections);

void update_graphics(Display *display, FrameMetadata *frame_metadata);

void send_matrix(Display *display, ESPConnection connections[]);

#endif
