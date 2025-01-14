#ifndef GTK_UTILS
#define GTK_UTILS

#define CELL_SIZE 40

#include "graphics.h"

// Custom structure to hold both the display and drawing area
typedef struct
{
  Display *display;
  GtkWidget *drawing_area;
} AppData;

// Function to render the Display using GTK 4
void draw_display(GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer user_data);

// Application activate callback
void on_activate(GApplication *app, gpointer user_data);

void update_gtk_window(Display *display, GtkWidget *widget);

// gboolean on_tick(GtkWidget *widget, GdkFrameClock *frame_clock, gpointer user_data);

// gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data);

#endif
