#ifndef GTK_UTILS
#define GTK_UTILS

#define CELL_SIZE 20

#include "graphics.h"
#include <gdk/gdkkeysyms.h> // For key symbols like GDK_KEY_W, GDK_KEY_Up, etc.
#include <gtk/gtk.h>

typedef struct
{
  Display *display;
  GtkWidget *drawing_area;
  ESPConnection *connections;
} AppData;

// Struct to track key states (example for movement)
typedef struct
{
  gboolean up;
  gboolean down;
  gboolean left;
  gboolean right;
  gboolean space;
} KeyState;

extern KeyState keys;

static gboolean on_key_pressed(GtkEventControllerKey *controller,
                               guint keyval,
                               guint keycode,
                               GdkModifierType state,
                               gpointer user_data);

static gboolean on_key_released(GtkEventControllerKey *controller,
                                guint keyval,
                                guint keycode,
                                GdkModifierType state,
                                gpointer user_data);

// Application activate callback
void on_activate(GApplication *app, gpointer user_data);

void on_draw(GtkDrawingArea *drawing_area, cairo_t *cr, int width, int height, gpointer user_data);

gboolean on_timeout(gpointer user_data);

#endif
