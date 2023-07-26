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
	size_t n = 10;
	char *ptprompt = malloc(sizeof(char) * n);
	ssize_t char_input;

	if (ptprompt == NULL) 
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/*promptprint();*/
		char_input = (getline(&ptprompt, &n, stdin));
		if (char_input == 1)
		{

			continue;
		}
		if (char_input != -1)
		{
			/*printf("%ld\n", char_input);*/
			shell_cmd(ptprompt, argc, argv, env);
			/*printf("%ld after shell_cmd\n", char_input);*/
		}
		else
			break;
	}
	free(ptprompt);
	return (0);
}

/**
*shell_cmd - hanle the input string and execute command
*@string:input string.
*@argc:argument counter.
*@argv:argument vector.
*@env: environnement variable.
*
*/
void shell_cmd(char *string, int argc, char **argv, char **env)
{
	char *cmd = "t", *cmd_path = NULL, *cmmd[20];
	int i;
	struct stat strtzrsa;

	(void)argc;
	/*(void)argv;*/

			cmd = strtok(string, " \t\n");
			if(cmd == NULL)
				return;
			for (i = 0; cmd != NULL; i++)
			{
				cmmd[i] = cmd;
				cmd = strtok(NULL, " \n");
			}
			cmmd[i] = NULL;


			if (strcmp(cmmd[0], "exit") == 0)
			{
				my_exit(cmmd, argc, argv, env);
			}


			if (strcmp(cmmd[0], "env") == 0)
			printenvironement();

			if (cmmd[0] != NULL && stat(cmmd[0], &strtzrsa) != 0)
				cmd_path = get_cmd_path(cmmd[0], argv);
			if (stat(cmmd[0], &strtzrsa) == 0)
				cmd_execution(cmmd[0], cmmd, env);
			else if (cmd_path)
				cmd_execution(cmd_path, cmmd, env);
}
/**
*printenvironement - print the envirment variable
*
*/
void printenvironement(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	printf("%s\n", environ[i]);
}
