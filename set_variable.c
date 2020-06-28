#include <stdio.h>
#include <string.h>

#include "set_variable.h"
#include "parse.h"

void handle_set_variable(Char_ptr* args, List_ptr variable_list)
{
  int length = get_length(args);

  if (length <= 2)
  {
    fprintf( stderr, "rsh: not enough arguments\n");
  }
  
    Char_ptr variable_name = "";
    int i = 2;
    while (args[i] != NULL)
    {
      variable_name = join(variable_name, args[i]);
      variable_name = join(variable_name, " ");
      i++;
    }
    variable_name[strlen(variable_name) -1] = '\0';
    add_to_end(variable_list, variable_name, args[0]);
}

int is_perform_variable(Char_ptr* args)
{
  int i = 0;
  while (args[i] != NULL)
  {
    if (args[i][0] == '$')
    {
      return 1;
    }
    i++;
  }
  return 0;
}

Char_ptr get_variable_command(Char_ptr command, List_ptr variable_list) {
  int position = 0;
  Node_ptr iterator = variable_list->head;
  while (iterator != NULL)
  {
    if (!strcmp(command, iterator->var))
    {
      return iterator->command;
    }
    position++;
    iterator = iterator->next;
  }
  return "wrong command";
}

int get_varable_command_index(Char_ptr* args)
{
  int i = 0;
  while (args[i] != NULL)
  {
    if (args[i][0] == '$')
    {
      return i;
    }
    i++;
  }
  return -1;
}
unsigned long count_length(char *text)
{
  int count;
  for (count = 0; text[count] != '\0'; count++)
    ;
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

void perform_variable(Char_ptr* args, List_ptr variable_list)
{
  int variable_command_indx = get_varable_command_index(args);
  Char_ptr* command = parse_command(args[variable_command_indx],'$');
  Char_ptr variable_command = get_variable_command(command[1] , variable_list);

  args[variable_command_indx] = variable_command;
}