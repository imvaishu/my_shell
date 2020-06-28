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

void ctrl_c_handler(int signal)
{
  exit(1);
}

void command_not_found_handler(Char_ptr command)
{
  printf("command not found: %s\n", command);
  exit(1);
}

int get_length(Char_ptr* args)
{
  size_t indx = 0;
  while (args[indx] != NULL)
  {
    indx++;
  }
  return indx;
}