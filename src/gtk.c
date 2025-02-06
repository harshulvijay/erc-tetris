#include "gtk.h"

KeyState keys = {0}; // Initialize all keys to FALSE

// Key press handler
static gboolean on_key_pressed(GtkEventControllerKey *controller,
                               guint keyval,
                               guint keycode,
                               GdkModifierType state,
                               gpointer user_data)
{
  switch (keyval)
  {
  case GDK_KEY_Up:
  case GDK_KEY_w:
    keys.up = TRUE;
    break;
  case GDK_KEY_Down:
  case GDK_KEY_s:
    keys.down = TRUE;
    break;
  case GDK_KEY_Left:
  case GDK_KEY_a:
    keys.left = TRUE;
    break;
  case GDK_KEY_Right:
  case GDK_KEY_d:
    keys.right = TRUE;
    break;
  case GDK_KEY_space:
    keys.space = TRUE;
    break;
  }

  return GDK_EVENT_STOP; // Prevent further propagation
}

// Key release handler
static gboolean on_key_released(GtkEventControllerKey *controller,
                                guint keyval,
                                guint keycode,
                                GdkModifierType state,
                                gpointer user_data)
{
  switch (keyval)
  {
  case GDK_KEY_Up:
  case GDK_KEY_w:
    keys.up = FALSE;
    break;
  case GDK_KEY_Down:
  case GDK_KEY_s:
    keys.down = FALSE;
    break;
  case GDK_KEY_Left:
  case GDK_KEY_a:
    keys.left = FALSE;
    break;
  case GDK_KEY_Right:
  case GDK_KEY_d:
    keys.right = FALSE;
    break;
  case GDK_KEY_space:
    keys.space = FALSE;
    break;
  }

  return GDK_EVENT_STOP;
}

void on_activate(GApplication *app, gpointer user_data)
{
  AppData *app_data = (AppData *)user_data;
  GtkWidget *window = gtk_application_window_new(GTK_APPLICATION(app));
  GtkWidget *drawing_area = gtk_drawing_area_new();
  // update the `drawing_area` pointer to point to our newly-created drawing area
  app_data->drawing_area = drawing_area;

  gtk_window_set_title(GTK_WINDOW(window), "Tetris");
  gtk_window_set_default_size(GTK_WINDOW(window), MAX_COLS * CELL_SIZE, MAX_ROWS * CELL_SIZE);

  gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(drawing_area), on_draw, app_data, NULL);
  gtk_window_set_child(GTK_WINDOW(window), drawing_area);
  g_timeout_add(TARGET_FRAME_TIME, (GSourceFunc)on_timeout, app_data);

  GtkEventController *controller = gtk_event_controller_key_new();
  g_signal_connect(controller, "key-pressed", G_CALLBACK(on_key_pressed), NULL);
  g_signal_connect(controller, "key-released", G_CALLBACK(on_key_released), NULL);
  gtk_widget_add_controller(window, controller);

  gtk_widget_show(window);
}

// Renders a matrix of colors
void on_draw(GtkDrawingArea *drawing_area, cairo_t *cr, int width, int height, gpointer user_data)
{
  AppData *app_data = (AppData *)user_data;

  double cell_width = (double)width / MAX_COLS;
  double cell_height = (double)height / MAX_ROWS;

  cairo_set_line_width(cr, 1.0);

  for (int row = 0; row < MAX_ROWS; ++row)
  {
    for (int col = 0; col < MAX_COLS; ++col)
    {
      Color color = get_pixel(app_data->display, row, col);

      cairo_set_source_rgb(cr, color.r / 255.0, color.g / 255.0, color.b / 255.0);
      cairo_rectangle(cr, col * cell_width, row * cell_height, cell_width, cell_height);
      cairo_fill(cr);
    }
  }
}

// Timeout callback (runs at regular intervals based on FPS)
gboolean on_timeout(gpointer user_data)
{
  AppData *app_data = (AppData *)user_data;

  update_graphics(app_data->display, NULL);
  // queue a redraw for the widget
  gtk_widget_queue_draw(app_data->drawing_area);
  send_matrix(app_data->display, app_data->connections);

  return TRUE;
}
