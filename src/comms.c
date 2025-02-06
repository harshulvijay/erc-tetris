#include "comms.h"

void send_matrix(Display *display, ESPConnection connections[])
{
  char message[NUM_DEVICES][4096] = {""}; // Array to hold messages for each ESP
  char temp[4096] = "";

  for (uint col = 0; col < MAX_COLS; col++)
  {
    int col_num = (col + 1);
    int esp_index = -1;
    int esp_col_start_index = -1;

    if (is_between_inclusive(col_num, 1, 4))
    {
      esp_index = 0;
      esp_col_start_index = 1;
    }
    else if (is_between_inclusive(col_num, 5, 8))
    {
      esp_index = 1;
      esp_col_start_index = 5;
    }
    else if (is_between_inclusive(col_num, 9, 12))
    {
      esp_index = 2;
      esp_col_start_index = 9;
    }
    else if (is_between_inclusive(col_num, 13, 16))
    {
      esp_index = 3;
      esp_col_start_index = 13;
    }
    else if (is_between_inclusive(col_num, 17, 20))
    {
      esp_index = 4;
      esp_col_start_index = 17;
    }

    if (esp_index == -1)
    {
      fprintf(stderr, "Invalid row number: %d\n", col_num);
      continue;
    }

    for (uint row = 0; row < MAX_ROWS; row++)
    {
      Color color = display->data[row][col];
      char hex[8];

      color_to_hex(color, hex);

      // Determine which ESP this pixel should be sent to
      long color_idx = strtol(hex, NULL, 16);
      char color_char = !!COLOR_CODES[color_idx] ? COLOR_CODES[color_idx] : 'v';

      sprintf(temp, "%s%d.%d&%c", strlen(message[esp_index]) > 0 ? "/" : "", col_num + 1 - esp_col_start_index, 40 - row, color_char);
      strcat(message[esp_index], temp);
    }
  }

  // Send messages to each ESP
  for (int i = 0; i < NUM_DEVICES; i++)
  {
    if (strlen(message[i]) > 0)
    {
      if (send_message(&connections[i], message[i]) < 0)
      {
        fprintf(stderr, "Failed to send message to ESP %d\n", i + 1);
      }
      else
      {
        printf("Message sent to ESP %d: %s\n", i + 1, message[i]);
      }
    }
  }
}
