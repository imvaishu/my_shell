#ifndef __REDIRECTION_H_
#define __REDIRECTION_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#include <stdlib.h>
#include <fcntl.h>
typedef char *Char_ptr;
int is_redirected(Char_ptr *command);
void handle_redirection(Char_ptr *command);

#endif