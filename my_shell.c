#include "main.h"



/**
*promptprint - print the prmpt
*
*/
void promptprint(void)
{
	_putchar('(');
	_putchar('$');
	_putchar(')');
	_putchar(' ');

}

/**
*cmd_execution - execution of a command
*@command:command to be executed
*@cmmd:argument
*@env: environnement variable
*
*Return:  0 if success
*/
void cmd_execution(char *command, char *cmmd[], char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
		perror("Error:fork");
	else if (pid == 0)
	{
		if (execve(command, cmmd, env) == -1)
			perror("Error:");
	}
	else
		wait(&status);
}


/**
*main - entry point for my simple shell for alx
*@argc:argument counter
*@argv:argument vector
*@env: environnement variable
*
*Return:  0 if success
*/
int main(int argc, char **argv, char **env)
{
	char *ptprompt, *cmd, *cmd_path, *cmmd[20];
	size_t n = 10;
	ssize_t char_input;
	int i;
	struct stat strtzrsa;

	(void)argc;
	(void)argv;
	ptprompt = malloc(sizeof(char) * n);
	while (1)
	{
		promptprint();
		char_input = (getline(&ptprompt, &n, stdin));
		if (char_input == 1)
		{
			continue;
		}
		if (char_input != -1)
		{
			cmd = strtok(ptprompt, " \t\n");
			for (i = 0; cmd != NULL; i++)
			{
				cmmd[i] = cmd;
				cmd = strtok(NULL, " \n");
			}
			cmmd[i] = NULL;
			if (cmmd[0] != NULL)
				cmd_path = get_cmd_path(cmmd[0]);
			if (stat(cmmd[0], &strtzrsa) == 0)
				cmd_execution(cmmd[0], cmmd, env);
			else if (cmd_path)
				cmd_execution(cmd_path, cmmd, env);
		}
		else
			break;
	}
	free(ptprompt);
	return (0);
}

