#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>

extern char **environ;


int _putchar(char c);
void shell_cmd(char *string, int argc, char **argv, char **env);
char *_getenv(const char *name);
char *get_cmd_path(char *command, char **argv);
void printenvironement(void);
void my_exit(char **str, int argc, char **argv, char **env);

size_t _getline(char **buf, size_t *size, FILE *stream);
char *_strtok(char *string, const char *delimiters);

int my_isdigit(int c);



#endif
