#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
*_getenv - a fonction to get the value of an envirement variable
*@name:name of variable
*
*Return:value of variable
*/
char *_getenv(const char *name)
{
	char **env = environ;
	unsigned int i;
	size_t len = strlen(name);


	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
		{
			return (&(environ[i][len + 1]));
		}
	}
	return (NULL);
}
