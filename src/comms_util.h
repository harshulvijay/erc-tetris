#ifndef COMMS_UTILS_H
#define COMMS_UTILS_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_DEVICES 5
// #define NUM_DEVICES 1

// Configuration structure for each ESP device
typedef struct
{
  const char *ip;
  int port;
  int first_strip_number;
} ESPConfig;

// Define configuration for all ESP devices
static const ESPConfig ESP_DEVICES[NUM_DEVICES] = {
    // {"192.168.120.49", 12341},
    // {"192.168.120.115", 12342},
    // {"192.168.120.53", 12343},
    // {"192.168.120.54", 12344},
    // {"192.168.83.233", 12346},
    // {"172.20.10.6", 12346},
    // {"172.20.10.6", 12346},
    // {"172.20.10.6", 12346},
    // {"172.20.10.6", 12346},
    // {"172.20.10.6", 12346}
    {"192.168.24.49", 12341, 1},
    {"192.168.24.115", 12342, 5},
    {"192.168.24.53", 12343, 9},
    {"192.168.24.54", 12344, 13},
    {"192.168.24.109", 12345, 17},
};

// Structure to hold socket and address information
typedef struct
{
  int socket;
  struct sockaddr_in address;
} ESPConnection;

// Function prototypes
ESPConnection *initialize_connections(void);

void cleanup_connections(ESPConnection *connections);

int send_message(ESPConnection *conn, const char *message);

#endif
