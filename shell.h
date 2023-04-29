#ifndef SHELL_H
#define SHELL_H

/*lib*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/*for parse data*/
#define BUFFER_SIZE 12
#define TOKEN_DELIMITERS " \t\r\n\a"

/*functions*/
char *shell_input();
char **shell_parse(char *input);
int shell_execute(char **commands, char **av, char **env);

#endif /*SHELL_H*/
