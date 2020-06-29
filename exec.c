#include "exec.h"
#include "parse.h"

void exec_call(Char_ptr *command)
{
  int pid = fork();
  if (pid == 0)
  {
    execvp(command[0], command);
    fprintf(stderr, "command not found: %s\n", *command);
    exit(-1);
  }
  else
  {
    wait(&pid);
    printf("\n");
  }
}
