#include "main.h"
#include <errno.h>
/**
*cmd_execution - execution of a command
*@command:command to be executed
*@cmmd:argument
*@env: environnement variable
*
*Return:  0 if success
*/
int cmd_execution(char *command, char *cmmd[], char **env)
{
	pid_t pid;
	int status, exit_status = 0, flag = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: fork");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(command, cmmd, env) == -1)
		{
			if (errno == ENOENT)
			{
				flag = 1;
			}
		}
		_exit(0);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (flag == 1)
				exit_status = 2;
		}
		return (exit_status);
	}
	return (0);
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
	int exit_status = 0;

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
			exit_status = shell_cmd(ptprompt, argc, argv, env);
			/*printf("%d after shell_cmd\n", exit_status);*/
		}
		else
			break;
	}
	free(ptprompt);
	return (exit_status);
}

/**
*shell_cmd - hanle the input string and execute command
*@string:input string.
*@argc:argument counter.
*@argv:argument vector.
*@env: environnement variable.
*
*Return:  status
*/
int shell_cmd(char *string, int argc, char **argv, char **env)
{
	char *cmd = "t", *cmd_path = NULL, *cmmd[20];
	int i, exs;
	struct stat strtzrsa;

	(void)argc;
			cmd = strtok(string, " \t\n");
			if (cmd == NULL)
				return (0);
			for (i = 0; cmd != NULL; i++)
			{
				cmmd[i] = cmd;
				cmd = strtok(NULL, " \n");
			}
			cmmd[i] = NULL;
			if (strcmp(cmmd[0], "exit") == 0)
				my_exit(cmmd, argc, argv, env);
			if (strcmp(cmmd[0], "env") == 0)
			printenvironement();
			if (cmmd[0] != NULL && stat(cmmd[0], &strtzrsa) != 0)
			{
				get_cmd_path(cmmd[0], argv);
				if (!cmd_path)
				{
					fprintf(stderr, "%s: %d: %s: not found\n", argv[0], 1, cmmd[0]);
					return (127);
				}
			}
			if (stat(cmmd[0], &strtzrsa) == 0)
			{
				exs = cmd_execution(cmmd[0], cmmd, env);
				if (exs == 2)
					exit(2);
			}
			else if (cmd_path)
				exs = cmd_execution(cmd_path, cmmd, env);
			else
				return (127);
			free(cmd_path);
			free(cmd);
			return (exs);
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
