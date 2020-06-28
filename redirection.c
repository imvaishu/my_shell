#include <stdlib.h>

#include "redirection.h"

int is_redirected(Char_ptr* command)
{
  int i = 0;
  while (command[i] != NULL)
  {
    for (size_t j = 0; command[i][j] != '\0'; j++)
    {
      if (command[i][j] == '>')
      {
        return 1;
      }
    }
    i++;
  }
  return 0;
}

void handle_redirection(Char_ptr *command)
{
  
}