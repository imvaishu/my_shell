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
  return command;
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

void perform_variable(Char_ptr* args, List_ptr variable_list)
{
  int variable_command_indx = get_varable_command_index(args);
  Char_ptr* command = parse_command(args[variable_command_indx],'$');
  Char_ptr variable_command = get_variable_command(command[1] , variable_list);

  args[variable_command_indx] = variable_command;
}

void handle_unset(Char_ptr *command,List_ptr variable_list)
{
  if (get_length(command) < 2)
  {
    printf("unset: not enough arguments\n");
    return;
  }
  int variable_index =search(variable_list,command[1]);
  if(remove_at(variable_list,variable_index))
  {
    return;
  }
  printf("unset: no such element: %s\n", command[1]);
}