#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <limits.h>

#include "linked_list.h"
#include "alias.h"
#include "parse.h"
#include "built_in.h"

int main(void)
{
  List_ptr alias_list = create_list();
  signal(SIGINT, SIG_IGN);
  char args[255];
  int status = 0;
  while (1)
  {
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    printf("Vaishnavi $%s:", cwd);
    gets(args);
    Char_ptr *command = parse_command(args);

    if (!strcmp(args, "exit"))
    {
      return 0;
    }

    if (handle_built_in(command, alias_list))
    {
      continue;
    }

    int pid = fork();
    if (pid == 0)
    {
      signal(SIGINT, ctrl_c_handler);
      execvp(command[0], command);
      command_not_found_handler(command[0]);
    }
    else
    {
      wait(&pid);
      printf("\n");
    }
  }
  return 0;
}