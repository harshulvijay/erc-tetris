#include "graphics.h"

void update_graphics(Display *display, FrameMetadata *frame_metadata)
{
  // NULL check
  if (!frame_metadata)
  {
    // todo
  }

  game_tick(display);
}

uint64_t get_current_time_ms()
{
#ifdef _WIN32
  LARGE_INTEGER frequency, counter;
  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&counter);
  return (counter.QuadPart * 1000) / frequency.QuadPart;
#else
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (uint64_t)(tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
#endif
}

void init_graphics_loop(Display *display, ESPConnection *connections)
{
  int frame_number = 0;
  double start_time = get_current_time_ms();
  double target_frame_time_ms = TARGET_FRAME_TIME;

  while (true)
  {
    double current_time = get_current_time_ms();
    double elapsed_time = current_time - start_time;

    // Calculate how many frames we should have processed so far
    int frames_to_process = elapsed_time / target_frame_time_ms;

    // Render each frame up to the current time
    while (frame_number < frames_to_process)
    {
      FrameMetadata frame_metadata = {
          frame_number,
      };

      update_graphics(display, &frame_metadata);
      send_matrix(display, connections);
      frame_number++;
    }

    // pause for 1 frame to avoid too much CPU usage
    wait(target_frame_time_ms);
  }
}
