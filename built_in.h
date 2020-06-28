#ifndef __BUILT_IN_H
#define __BUILT_IN_H

#include <unistd.h>
#include  <string.h>
#include <stdio.h>

#include "alias.h"
#include "redirection.h"
#include "set_variable.h"

int handle_built_in(Char_ptr *command, List_ptr alias_list, List_ptr variable_list);


#endif