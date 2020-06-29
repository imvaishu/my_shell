#include "redirection.h"

int is_redirected(Char_ptr *command)
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
  int file_discriptor;
  if(!strcmp(command[1],">")){
  file_discriptor = open(command[2], O_CREAT | O_RDWR, 0666);
  }
  else
  {
   file_discriptor = open(command[2],O_APPEND | O_RDWR);
  }
  int save_output_stream = dup(1);
  dup2(file_discriptor, 1);
  close(file_discriptor);
  int pid = fork();
  if (pid == 0)
  {
    execlp(command[0], command[0], NULL);
    fprintf(stderr,"%s: command not found\n",command[0]);
    execlp("rm","rm",command[2],NULL);
    exit(0);
  }
  else
  {
    wait(&pid);
    dup2(save_output_stream, 1);
  }
}