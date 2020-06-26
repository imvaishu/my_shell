#include "built_in.h"

int handle_built_in(Char_ptr *command, List_ptr alias_list)
{
  if (strcmp(command[0], "cd") == 0)
  {
    chdir(command[1]);
    return 1;
  }
  
  if (is_command_alias(command, alias_list))
  {
    perform_alias(command, alias_list);
    return 1;
  }

  if (!strcmp(command[0], "alias"))
  {
    handle_alias(command, alias_list);
    return 1;
  }

  if (!strcmp(command[0], "unalias"))
  {
    handle_unalias(command, alias_list);
    return 1;
  }
  return 0;
}
