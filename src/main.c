#include "graphics.h"
#include "gtk.h"
#include <stdio.h>

int main(int argc, char **argv)
{
  Display display = {0};

  // Create AppData structure to hold both display and drawing area
  AppData app_data = {&display, NULL};

  // Create a GtkApplication
  GtkApplication *app = gtk_application_new("com.game.MyTetris", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(on_activate), &app_data);

  // init_graphics_loop(&display);

  // Run the application
  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
