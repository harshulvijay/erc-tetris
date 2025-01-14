#include "gtk.h"

// Function to render the Display using GTK 4
void draw_display(GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer user_data)
{
  Display *display = (Display *)user_data;

  // Calculate dimensions of each cell (pixel)
  double cell_width = (double)width / MAX_COLS;
  double cell_height = (double)height / MAX_ROWS;

  // Loop through the display matrix and render each cell
  for (int row = 0; row < MAX_ROWS; ++row)
  {
    for (int col = 0; col < MAX_COLS; ++col)
    {
      Color color = display->data[row][col];

      // Set the color for the current cell
      cairo_set_source_rgb(cr, color.r / 255.0, color.g / 255.0, color.b / 255.0);

      // Draw the rectangle
      cairo_rectangle(cr, col * cell_width, row * cell_height, cell_width, cell_height);
      cairo_fill(cr);
    }
  }
}

void update_gtk_window(Display *display, GtkWidget *widget)
{
  update_graphics(1, display);
  gtk_widget_queue_draw(widget);
}

// Custom draw function to render the matrix of colors
void on_draw(GtkDrawingArea *drawing_area, cairo_t *cr, int width, int height, gpointer user_data)
{
  AppData *app_data = (AppData *)user_data;

  // Set up Cairo drawing settings
  cairo_set_line_width(cr, 1.0);

  // Calculate dimensions of each cell (pixel)
  double cell_width = (double)width / MAX_COLS;
  double cell_height = (double)height / MAX_ROWS;

  // Draw the matrix of colors
  for (int row = 0; row < MAX_ROWS; ++row)
  {
    for (int col = 0; col < MAX_COLS; ++col)
    {
      Color color = app_data->display->data[row][col];

      // Set the color
      cairo_set_source_rgb(cr, color.r / 255.0, color.g / 255.0, color.b / 255.0);

      // Draw a rectangle (pixel)
      cairo_rectangle(cr, col * cell_width, row * cell_height, cell_width, cell_height); // 20x20 pixels for each "cell"
      cairo_fill(cr);
    }
  }
}
// gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data)
// {
//   Display *display = (Display *)user_data;

//   for (int row = 0; row < MAX_ROWS; ++row)
//   {
//     for (int col = 0; col < MAX_COLS; ++col)
//     {
//       Color color = display->data[row][col];

//       // Set the color
//       cairo_set_source_rgb(cr, color.r / 255.0, color.g / 255.0, color.b / 255.0);

//       // Draw a rectangle (pixel)
//       cairo_rectangle(cr, col, row, 1, 1);
//       cairo_fill(cr);
//     }
//   }

//   return FALSE;
// }

// Timeout callback (runs at regular intervals based on FPS)
gboolean on_timeout(gpointer user_data)
{
  AppData *app_data = (AppData *)user_data;
  // Display *display = (Display *)user_data;

  update_graphics(2, app_data->display);

  // Queue the widget for a redraw (trigger the on_draw callback)
  gtk_widget_queue_draw(app_data->drawing_area);

  // Return TRUE to keep the timeout active (to repeat at the same interval)
  return TRUE;
}

void on_activate(GApplication *app, gpointer user_data)
{
  AppData *app_data = (AppData *)user_data;

  // Create a window
  GtkWidget *window = gtk_application_window_new(GTK_APPLICATION(app));
  gtk_window_set_title(GTK_WINDOW(window), "Tetris");
  gtk_window_set_default_size(GTK_WINDOW(window), MAX_COLS * CELL_SIZE, MAX_ROWS * CELL_SIZE);

  // Create a drawing area and set its draw function
  GtkWidget *drawing_area = gtk_drawing_area_new();
  app_data->drawing_area = drawing_area;
  gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(drawing_area), on_draw, app_data, NULL);

  // Add the drawing area to the window
  gtk_window_set_child(GTK_WINDOW(window), drawing_area);

  // gtk_widget_add_tick_callback(drawing_area, on_tick, display, NULL);
  g_timeout_add(TARGET_FRAME_TIME, (GSourceFunc)on_timeout, app_data);

  // Show the window
  gtk_widget_show(window);
}
