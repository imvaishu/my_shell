#ifndef __PARSE_H
#define __PARSE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

typedef char* Char_ptr;

Char_ptr *parse_command(Char_ptr instruction,char splitter);

int get_length(Char_ptr* args);

Char_ptr join(char *text1, char *text2);

#endif