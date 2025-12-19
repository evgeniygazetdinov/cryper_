#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define PRINT_TYPE(x) _Generic((x), \
    int: "int",                     \
    char: "char",                   \
    float: "float",                 \
    double: "double",               \
    char *: "char*",                \
    const char *: "const char*",    \
    void *: "void*",                \
    char **: "char**",              \
    default: "unknown type")

FILE *open_text_file()
{
  FILE *file = fopen("random_text.txt", "r");
  if (!file)
  {
    printf("read error");
  };
  return file;
}

int get_file_size(FILE *file)
{
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  return file_size;
}

void fill_array_text_chars(char *arr_data, FILE *file)
{
  int count = 0;
  int ch;
  while ((ch = fgetc(file)) != EOF)
  {
    arr_data[count] = ch;
    count += 1;
  }
}

void read_by_each_line(char *content, int *counter)
{
      setlocale(LC_ALL, "el_GR.UTF-8");
  for (int i = 0; i < *counter; i++)
  {
    if (content[i] == ' ' || content[i] == '\0' || content[i] == ','
    || content[i] == '\n' || content[i] == '\t' || content[i] == '\r'
    || content[i] == '\v' || content[i] == '\f') {
      printf(" ");
    } 
    else{
          printf("%c", content[i]);
    }

  }
  printf("\n");

}
