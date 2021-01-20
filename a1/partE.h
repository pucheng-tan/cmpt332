#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <pwd.h>
#include <sys/types.h>

char *input;

struct passwd *pwd;

void prompt();

int readCommand(char **command, char **paraArr);

void builtIn(char *command, char **paraArr);

int execute(char *command, char **paraArr);