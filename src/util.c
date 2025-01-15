#include "util.h"

// function(s) dependent on platform-specific functions
#ifdef _WIN32
#include <Windows.h>
#elif __linux__
#include <unistd.h>
#else
#error "Unsupported platform"
#endif

void wait(int time_in_ms)
{
#ifdef _WIN32
  Sleep(time_in_ms);
#else
  usleep(time_in_ms);
#endif
}
