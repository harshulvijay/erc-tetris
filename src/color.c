#include "color.h"
#include <stdio.h>

Color use_color(uint8 r, uint8 g, uint8 b)
{
  Color color;

  color.r = r;
  color.g = g;
  color.b = b;

  return color;
};

void print_matrix_to_file(const char *filename, int rows, int cols, Color matrix[rows][cols])
{
  // Open the file for writing
  FILE *file = fopen(filename, "w");
  if (file == NULL)
  {
    perror("Error opening file");
    return; // Return early if the file cannot be opened
  }

  // Write the matrix to the file
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      Color color = matrix[i][j];
      fprintf(file, "(%d, %d, %d) ", color.r, color.g, color.b);
    }
    fprintf(file, "\n"); // New line after each row
  }

  // Close the file after writing
  if (fclose(file) != 0)
  {
    perror("Error closing file");
    return;
  }

  printf("Matrix successfully printed to %s\n", filename);
}
