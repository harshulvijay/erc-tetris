#include "comms.h"

ESPConnection *initialize_connections(void)
{
  ESPConnection *connections = malloc(NUM_DEVICES * sizeof(ESPConnection));
  if (!connections)
  {
    return NULL;
  }

  for (int i = 0; i < NUM_DEVICES; i++)
  {
    // Create socket
    connections[i].socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (connections[i].socket < 0)
    {
      perror("Socket creation failed\n");
      cleanup_connections(connections);
      return NULL;
    }

    // Configure address
    connections[i].address.sin_family = AF_INET;
    connections[i].address.sin_port = htons(ESP_DEVICES[i].port);
    if (inet_pton(AF_INET, ESP_DEVICES[i].ip, &connections[i].address.sin_addr) <= 0)
    {
      perror("Invalid address\n");
      cleanup_connections(connections);
      return NULL;
    }
  }

  return connections;
}

void cleanup_connections(ESPConnection *connections)
{
  if (connections)
  {
    for (int i = 0; i < NUM_DEVICES; i++)
    {
      if (connections[i].socket >= 0)
      {
        close(connections[i].socket);
      }
    }
    free(connections);
  }
}

int send_message(ESPConnection *conn, const char *message)
{
  size_t message_len = strlen(message);
  return sendto(conn->socket, message, message_len, 0,
                (struct sockaddr *)&conn->address, sizeof(struct sockaddr_in));
}
