#include "main.h"

/**
*get_cmd_path - a fonction to get the cmd full path
*@command:input command
*
*Return:  command path
*/
char *get_cmd_path(char *command, char **argv)
{
	char *path2 = _getenv("PATH"), *path;
	char *path_token;
	char *full_cmd;
	struct stat starf;

	path = strdup(path2);
	path_token = _strtok(path, ":");

	while (path_token)
	{
		full_cmd = malloc(strlen(path_token) + strlen(command) + 2);
		if (full_cmd == NULL)
		{
			printf("error malloc\n");
			return (NULL);
		}


		strcpy(full_cmd, path_token);

		strcat(full_cmd, "/");

		strcat(full_cmd, command);

		if (stat(full_cmd, &starf) == 0)
		{
			free(path);
			return (full_cmd);
		}


		free(full_cmd);
		path_token = _strtok(NULL, ":");
	}
	free(path);
	fprintf(stderr, "%s: %d: %s: not found\n", argv[0], 1, command);
		/* Exit with status 127 to indicate command not found*/
		_exit(127);
	return (NULL);
}

