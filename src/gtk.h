#ifndef GTK_UTILS
#define GTK_UTILS

#define CELL_SIZE 20

#include "graphics.h"

typedef struct
{
  Display *display;
  GtkWidget *drawing_area;
} AppData;

// Application activate callback
void on_activate(GApplication *app, gpointer user_data);

void on_draw(GtkDrawingArea *drawing_area, cairo_t *cr, int width, int height, gpointer user_data);

gboolean on_timeout(gpointer user_data);

#endif
