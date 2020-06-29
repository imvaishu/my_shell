#ifndef __EXEC_H_
#define __EXEC_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <limits.h>

typedef char * Char_ptr;

void exec_call(Char_ptr *args);

#endif