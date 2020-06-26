#ifndef __PARSE_H
#define __PARSE_H

typedef char* Char_ptr;

Char_ptr *parse_command(Char_ptr instruction);

void ctrl_c_handler(int signal);

void command_not_found_handler(Char_ptr command);

#endif