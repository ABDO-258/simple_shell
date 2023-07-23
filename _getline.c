#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/**
*_getline - get input from the stdin and store it in a buffer
*@buf:buffer to store the input
*@size:size of the buffer
*@stream: the stdin (the place to get input from)
*
*Return:  number of char the function got from stdin or -1 if error
*/


size_t _getline(char **buf, size_t *size, FILE *stream)
{
	int fd = fileno(stream);
	int c;
	size_t i = 0;

	while ((c = read(fd, &((*buf)[i]), 1)) == 1 &&
	 (*buf)[i] != '\n' && (*buf)[i] != '\0')
	{
		if ((*size) <= i)
		{
			(*size) *= 2;
			*buf = realloc(*buf, sizeof(char) * (*size));
		}
		i++;
	}

	/* Check for read errors or end-of-file condition*/
	if (c == -1)
	{
		perror("Error reading input");
	}
	else if (c == 0 && i == 0)
	{
		/* End of file reached, return -1 to indicate end-of-file*/
		return (-1);
	}

	if (c == 1)
	{
		(*buf)[i++] = '\n';
	}

	(*buf)[i] = '\0';

	return (i);
}



































































































































































































