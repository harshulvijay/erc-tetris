#include "comms.h"
#include "graphics.h"
#include "gtk.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
  srand(time(NULL));

  ESPConnection *connections = initialize_connections();
  if (!connections)
  {
    fprintf(stderr, "Failed to initialize connections\n");
    return EXIT_FAILURE;
  }

  // initialize color codes
  init_color_codes();

  Display display = {0};

  // Create AppData structure to hold both display and drawing area
  AppData app_data = {&display, NULL, .connections = connections};

  // Create a GtkApplication
  GtkApplication *app = gtk_application_new("com.game.MyTetris", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(on_activate), &app_data);

  // init_graphics_loop(&display, NULL);
  // init_graphics_loop(&display, connections);

  // Run the application
  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  cleanup_connections(connections);

  return 0;
}
