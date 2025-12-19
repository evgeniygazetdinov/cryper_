#include "cr.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>




int main()
{
  FILE *file = open_text_file();
  int file_size = get_file_size(file);
  char *content = malloc(file_size);
  fill_array_text_chars(content, file);
  setlocale(LC_ALL, "el_GR.UTF-8");
  read_by_each_line(content, &file_size);
  crypt(content, &file_size);
  read_by_each_line(content, &file_size);
  decrypt(content, &file_size);
  read_by_each_line(content, &file_size);
  free(content);
  fclose(file);
  return 0;
}