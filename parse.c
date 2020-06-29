#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"

Char_ptr *parse_command(Char_ptr instruction,char splitter)
{

  Char_ptr *command = malloc(sizeof(char *) * 10);
  int command_count = 0;
  char arg[10];
  int arg_count = 0;
  for (int i = 0; i < 255; i++)
  {
    char character = instruction[i];
    if (character == splitter|| character == '\0')
    {
      command[command_count] = malloc(sizeof(char) * arg_count);
      strncpy(command[command_count++], arg, arg_count);
      arg_count = 0;
    }
    else
      arg[arg_count++] = character;
    if (character == '\0')
      break;
  }
  command[command_count] = NULL;
  return command;
}

int get_length(Char_ptr* args)
{
  size_t index = 0;
  while (args[index] != NULL)
  {
    index++;
  }
  return index;
}

unsigned long count_length(char *text)
{
  int count;
  for (count = 0; text[count] != '\0'; count++);
  return count;
}

char *join(char *text1, char *text2)
{
  unsigned long text1_length = count_length(text1);
  unsigned long text2_length = count_length(text2);
  char *joined_string = malloc((text1_length + text2_length + 1) * sizeof(char));
  int j = 0; 
  for (unsigned long  i = 0; i < text1_length + text2_length; i++)
  {
    if (i < text1_length)
    {
      joined_string[i] = text1[i];
    }
    else
    {
      joined_string[i] = text2[j];
      j++;
    }
  }
  return joined_string;
}
