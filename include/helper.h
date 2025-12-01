#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
FILE* open_text_file();
int get_file_size(FILE *file);
void fill_array_text_chars(char *arr_data, FILE *file);
void read_by_each_line(char *content, int counter);
