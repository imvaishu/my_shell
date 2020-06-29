#include "linked_list.h"
#include "parse.h"
#include "built_in.h"
#include "exec.h"
#include "alias.h"
#include "set_variable.h"

int main(void)
{
  List_ptr alias_list = create_list();
  List_ptr variable_list = create_list();

  signal(SIGINT, SIG_IGN);
  char args[255];
  int status = 0;
  while (1)
  {
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    printf("Vaishnavi $%s:", cwd);
    gets(args);
    Char_ptr *command = parse_command(args, ' ');

    if (!strcmp(args, "exit"))
    {
      return 0;
    }

    if (handle_built_in(command, alias_list, variable_list))
    {
      continue;
    }

    exec_call(command);
  }
  return 0;
}