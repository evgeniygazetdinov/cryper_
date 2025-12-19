
#include "stdio.h"
#include "string.h"
#include "helper.h"
#include "ctype.h"

char LOWERCASE_ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";
char UPPERCASE_ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char DIGITS[] = "0123456789";
char PUNKT_CHARS[] = ".,!?;:'\"-()[]{}@#$%^&*+=|\\/~<>`^_ ";

char PUNKT_CODE_CHARS[] = "αβγδεζηθικλμνξοπρστυφχψω∀∃∂∇∈∉∩∪∧∨•";

char* PUNKT_CHANGE = "^";
const int SHIFT = 2;
const int ALPHABET_SIZE = 29;

int is_punkt_char(char * char_for_compare){
  if (*char_for_compare == ' ' || *char_for_compare == ',' 
    || *char_for_compare == '\n'){

        return 1;
    }
    return 0;
}

void handle_punkt_chars(char *array_for, int * position, char * crypted_array){
if (isspace(array_for[*position]) || array_for[*position] == ' ' || array_for[*position] == '\0') {
      crypted_array[*position] = ' ';
      array_for[*position] = ' ';
    }
    // else if (array_for[*position] == '\n'){
    //   array_for[*position] = '\n';
    // }
    else if (array_for[*position] == ','){
      crypted_array[*position] = ',';
      printf("################################################# here\n");
    }
    // else if (array_for[*position] == ';'){
    //   array_for[*position] = ';';
    // }
    // else if (array_for[*position] == '\t'){
    //   array_for[*position] = '\t';
    // }
}


int find_position(char for_find, char **current_case)
{
  for (int i = 0; i < sizeof(LOWERCASE_ALPHABET) - 1; i++)
  {

    if (LOWERCASE_ALPHABET[i] == for_find)
    {
      *current_case = "lower";
      return i;
    }
  }
  for (int i = 0; i < sizeof(UPPERCASE_ALPHABET) - 1; i++)
  {
    if (UPPERCASE_ALPHABET[i] == for_find)
    {
      *current_case = "upper";
      return i;
    }
  }
  return -1;
}

int get_new_position(int *position, char **current_case, char **array_for_choose)
{
  int new_position;


  new_position = (*position + SHIFT) % ALPHABET_SIZE;

  if (new_position < 0)
  {
    new_position += ALPHABET_SIZE;
  }
  if (strcmp(*current_case, "lower") == 0)
  {
    *array_for_choose = LOWERCASE_ALPHABET;
  }
  else if (strcmp(*current_case, "upper") == 0)
  {
    *array_for_choose = UPPERCASE_ALPHABET;
  }
  else
  {
    *array_for_choose = PUNKT_CHARS;
  }
  return new_position;
}
int decript_position(int *position, char **current_case, char **array_for_choose)
{
  int new_position = (*position - SHIFT) % ALPHABET_SIZE;
  if (*position == 666){
    new_position = 666;
  }
  else{
  if (new_position < 0)
  {
    new_position += ALPHABET_SIZE;
  }
}
  if (strcmp(*current_case, "lower") == 0)
  {
    *array_for_choose = LOWERCASE_ALPHABET;
  }
  else if (strcmp(*current_case, "upper") == 0)
  {
    *array_for_choose = UPPERCASE_ALPHABET;
  }
  else if (strcmp(*current_case, "chars") == 0)
  {
    *array_for_choose = PUNKT_CHARS;
    
  }
  else if(strcmp(*current_case, "decode_chars"))
  {
      *array_for_choose = PUNKT_CODE_CHARS;
  }
  else
  {
    *array_for_choose = PUNKT_CODE_CHARS;
  }
  return new_position;
}

void crypt(char *array_data, int *file_size)
{
  int counter = *file_size;
  char crypted_array[*file_size];

  for (int i = 0; i < counter; i++)
  {
    char *current_case;
    if(is_punkt_char(&array_data[i])){
      handle_punkt_chars(array_data, &counter, crypted_array);
    }
    else{  
      int position = find_position(array_data[i], &current_case);
      char *array_with_chars;
      int new_position = get_new_position(&position, &current_case, &array_with_chars);

      crypted_array[i] = array_with_chars[new_position];
    }
  }
  for (int i = 0; i < counter; i++)
  {

    array_data[i] = crypted_array[i];
  }
}
void decrypt(char *array_data, int *file_size)
{
  int counter = *file_size;
  char decript_array[counter];
  for (int i = 0; i < counter; i++)
  {
    char *current_case;
    int position = find_position(array_data[i], &current_case);
    char *array_with_chars;
    if (is_punkt_char(&decript_array[i])){
      handle_punkt_chars(array_data, &i, decript_array);
    }
    else{
      int new_position = decript_position(&position, &current_case, &array_with_chars);
      decript_array[i] = array_with_chars[new_position];
    }

  }
  for (int i = 0; i < counter; i++)
  {

    array_data[i] = decript_array[i];
  }
}
