#include "main.h"

/**
*get_cmd_path - a fonction to get the cmd full path
*@command:input command
*
*Return:  command path
*/
char *get_cmd_path(char *command)
{
	char *path2 = _getenv("PATH"), *path;
	char *path_token;
	char *full_cmd;
	struct stat starf;

	path = strdup(path2);
	path_token = strtok(path, ":");

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
		path_token = strtok(NULL, ":");
	}
	free(path);
	printf("Command not found.\n");
	return (NULL);
}

