#include <stdio.h>

const char *my_strchr(const char *str, char character)
{
  while (*str)
  {
    if (*str == character)
      return str;
    str++;
  }
  if (character == '\0')
    return str;
  return NULL;
}

int main()
{
  char string[100];
  char character;
  fgets(string, sizeof(string), stdin);
  scanf(" %c", &character);
  const char *position = my_strchr(string, character);

  if (position)
    printf("Character %c at position %ld\n", character, position - string + 1);
  else
    printf("Character not found\n");
}