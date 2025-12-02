#include "helper.h"
#include <stdlib.h>
#include <stdio.h>



int main(){
    FILE *file = open_text_file();
    long file_size = get_file_size(file);
    char *content = malloc(file_size);    
    fill_array_text_chars(content, file);
    read_by_each_line(content, file_size);
    free(content);
    fclose(file);
    return 0;
}