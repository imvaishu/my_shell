#ifndef __SET_VARIABLE_H_
#define __SET_VARIABLE_H_

#include "linked_list.h"
#include "parse.h"

void handle_set_variable(Char_ptr* args, List_ptr variable_list);

int is_perform_variable(Char_ptr* args);

void perform_variable(Char_ptr* args, List_ptr variable_list);

void handle_unset(Char_ptr *command,List_ptr variable_list);

#endif