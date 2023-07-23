#include "main.h"
/**
*my_exit - hanle the input string and execute command
*@str:input string.
*@argc:argument counter.
*@argv:argument vector.
*@env: environnement variable.
*
*/
void my_exit(char **str, int argc, char **argv, char **env)
{
	int i, arg;

	(void)env;
	(void)argc;
	(void)argv;

	if (!str[1])
	{
		free(*str);
		exit(0);
	}
	else
	{
		for (i = 0; str[1][i] != '\0'; i++)
		{
			if (my_isdigit(str[1][i]) == 1)
			{
				perror("gfhs"); /*i have to change this to handle the exit argument error*/
			}
			else
			{
				arg = atoi(str[1]);
				free(*str);
				exit(arg);
			}
		}
	}
}
