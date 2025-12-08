
#include "stdio.h"
#include "string.h"

// probably replace by struct
// and reformat by one array
const char LOWERCASE_ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";
const char UPPERCASE_ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char DIGITS[] = "0123456789";
const char PUNKT_CHARS[] = ".,!?;:'\"-()[]{}@#$%^&*+=|\\/~<>";
const char PUNKT_CODE_CHARS[] =   "αβγδεζηθικλμνξοπρστυφχψω∀∃∂∇∈∉∩";
const int SHIFT = 2;
const int ALPHABET_SIZE = 29;


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
  for (int i = 0; i < sizeof(UPPERCASE_ALPHABET) - 1; i++)
  {
    if (PUNKT_CHARS[i] == for_find)
    {
      *current_case = "chars";
      return i;
    }
  }
  return -1;
}

void crypt(char *array_data, int *file_size)
{
  char crypted_array[*file_size];

  for (int i = 0; i < *file_size; i++)
  {
    char *current_case;
    int position = find_position(array_data[i], &current_case);
    int new_position = (position + SHIFT) % ALPHABET_SIZE;
    if (new_position < 0){
      new_position+= ALPHABET_SIZE;
    }
    char * array_for_choose;
    if (strcmp(current_case, "lower") == 0) 
    {
      array_for_choose = LOWERCASE_ALPHABET;
    } 
    else if (strcmp(current_case, "upper") == 0)
    {
      array_for_choose = UPPERCASE_ALPHABET;
    }
    else if (strcmp(current_case, "chars") == 0)
    {
      array_for_choose = PUNKT_CODE_CHARS;
    }
    else
    {
      array_for_choose = LOWERCASE_ALPHABET;
    }
    crypted_array[i] = array_for_choose[new_position];
  }
      printf("%s\n", crypted_array);
}
void decript(char *array_data, int file_size)
{
}
