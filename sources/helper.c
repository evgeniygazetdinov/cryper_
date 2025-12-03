#include "helper.h"
#include <stdio.h>
#include <stdlib.h>

FILE *open_text_file() {
  FILE *file = fopen("random_text.txt", "r");
  if (!file) {
    printf("read error");
  };
  return file;
}

int get_file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  return file_size;
}

void fill_array_text_chars(char *arr_data, FILE *file) {
  int count = 0;
  int ch;
  while ((ch = fgetc(file)) != EOF) {
    arr_data[count] = ch;
    count += 1;
  }
}

void read_by_each_line(char *content, int counter) {
  for (int i = 0; i < counter; i++) {
    printf("%c", content[i]);
  }
  printf("\n");
}
