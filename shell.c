#include "shell.h"

/**
 * main - UNIX command line interpreter.
 *
 * @ac: argc
 * @av: argv
 * @env: environent
 *
 * Return:0
 */
int main(int ac, char **av, char **env)
{
	char *input;
	char **parse;
	char **envTemp;
	int stat = 1;

	while (ac && stat)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		input = shell_input();

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			exit(0);
		}

		if (strcmp(input, "env") == 0)
		{
			envTemp = env;
			while (*envTemp)
			{
				printf("%s\n", *envTemp++);
			}
			free(input);
			continue;
		}

		parse = shell_parse(input);
		stat = shell_execute(parse, av, env);

		free(input);
		free(parse);
	}


	return (0);
}
