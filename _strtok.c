#include <stdio.h>
#include <string.h>

/**
*_strtok - split a string by the delimiters
*@string:the string you want to split
*@delimiters:the delimiters
*
*Return:  a part of the input string or null
*/
char *_strtok(char *string, const char *delimiters)
{
	static char *nextToken;
	char *tokenStart;
	char *tokenEnd = NULL;
	const char *delimiter;

	if (string != NULL)
	{
		nextToken = string;
	}
	else if (nextToken == NULL)
		return (NULL);
	tokenStart = nextToken;
	while (*nextToken != '\0')
	{
		delimiter = delimiters;
		while (*delimiter != '\0')
		{
			if (*nextToken == *delimiter)
			{
				*nextToken = '\0';  /*Replace delimiter with null terminator*/
				tokenEnd = nextToken;
				nextToken++;
				return (tokenStart);
			}
			delimiter++;
		}
		nextToken++;
	}
	if (tokenEnd != NULL)
	{
		return (tokenStart);
	}
	return (NULL);
}
