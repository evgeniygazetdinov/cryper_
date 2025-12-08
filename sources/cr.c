
#include "stdio.h"
#include "string.h"
#include "helper.h"

char LOWERCASE_ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";
char UPPERCASE_ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char DIGITS[] = "0123456789";
char PUNKT_CHARS[] = ".,!?;:'\"-()[]{}@#$%^&*+=|\\/~<>";
char PUNKT_CODE_CHARS[] = "αβγδεζηθικλμνξοπρστυφχψω∀∃∂∇∈∉∩";
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

int get_new_position(int *position, char **current_case, char **array_for_choose)
{
  int new_position = (*position + SHIFT) % ALPHABET_SIZE;
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
  else if (strcmp(*current_case, "chars") == 0)
  {
    *array_for_choose = PUNKT_CODE_CHARS;
  }
  else
  {
    *array_for_choose = LOWERCASE_ALPHABET;
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
    int position = find_position(array_data[i], &current_case);
    char *array_with_chars;
    int new_position = get_new_position(&position, &current_case, &array_with_chars);
    crypted_array[i] = array_with_chars[new_position];
  }
  read_by_each_line(crypted_array, &counter);
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
    int new_position = get_new_position(&position, &current_case, &array_with_chars);
    decript_array[i] = array_with_chars[new_position];
  }
}
