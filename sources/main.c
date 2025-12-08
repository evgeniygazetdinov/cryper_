#include "cr.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *file = open_text_file();
  int file_size = get_file_size(file);
  char *content = malloc(file_size);
  fill_array_text_chars(content, file);
  // printf("size of file size %d", file_size);
  crypt(content, &file_size);
  free(content);
  fclose(file);
  // printf("over\n");
  return 0;
}