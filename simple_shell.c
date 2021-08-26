#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/**
* type_prompt - opens a window
*
*/
void type_prompt(void)
{
static int first_time = 1;
if (first_time)
{
const char *CLEAR_SCREEN_ANSI = " \033[1;1H\033[2J";
write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
first_time = 0;
}
printf("#cisfun$ ");
}
/**
* read_command - reads strings and separates command from parameters
*@cmd: the command variable - array of characters
*@par: the parameters - array of strings
*
*/
void read_command(char cmd[], char *par[])
{
char *line = malloc(sizeof(char) * 1024);
int count = 0, i = 0, j = 0;
char *array[100], *pch;
/*read one line*/
for (;;)
{
int c = fgetc(stdin);
line[count++] = (char) c;
if (c == '\n')
	break;
}
if (count == 1)
	return;
pch = strtok(line, " \n");
/* parse lines into words*/
while (pch != NULL)
{
array[i++] = strdup(pch);
pch = strtok(NULL, " \n");
/*first word is the command*/
strcpy(cmd, array[0]);
/*others are parameters*/
for (j = 0; j < i; j++)
	par[j] = array[j];
par[j] = NULL;
}
free(line);
/*for (j = 0; j < 100; j++)
{
array[j] = "";
}*/
free(pch);
}
/**
* main - beginning of execution
*Return: 0 if successful
*/
int main(void)
{
char cmd[100], command[100], *parameters[20];
/*environment variable*/
char *envp[] = {(char *) "PATH=/bin", (char *)0};
/*long unsigned int j; */
while (1)
{
type_prompt();
read_command(command, parameters);
if (fork() != 0)
	wait(NULL);
else
{
strcpy(cmd, "/bin/");
strcat(cmd, command);
execve(cmd, parameters, NULL);
}
if (strcmp(cmd, "exit") == 0)
	break;
}
return (0);
}
