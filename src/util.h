#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdint.h>
#include <time.h>

// for convenience
typedef uint8_t uint8;
typedef unsigned int uint;

// function(s) dependent on platform-specific functions
void wait(int time_in_ms);

#endif
