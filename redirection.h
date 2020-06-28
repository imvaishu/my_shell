#ifndef __REDIRECTION_H_
#define __REDIRECTION_H_

typedef char *Char_ptr;
int is_redirected(Char_ptr *command);
void handle_redirection(Char_ptr *command);

#endif