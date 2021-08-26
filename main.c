#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
void type_prompt()
{
static int first_time = 1;
if(first_time)
{
const char* CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";
write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
first_time = 0;
}
printf("#");
}
void read_command(char cmd[], char *par[])
{
char *line = malloc(sizeof(char) * 1024);
int count = 0, i = 0, j = 0;
char *array[100], *pch;
//read one line
for(;;)
{
int c = fgetc(stdin);
line[count++] = (char) c;
if(c == '\n') break;
}
if(count == 1) return;
pch = strtok(line, " \n");
// parse lines into words
while(pch != NULL)
{
array[i++] = strdup(pch);
pch = strtok(NULL, " \n");
//first word is the command
strcpy(cmd, array[0]);
//others are parameters
for(int j = 0; j < i; j++)
    par[j] = array[j];
par[j] = "\0";
}
free(line);
for(j = 0; j < sizeof(*array); j++)
{
array[j] = "";
}
free(pch);
}
int main()
{
char cmd[100], command[100], *parameters[20];
//environment variable
char *envp[] = {(char *) "PATH=/bin", 0};
int j;
while (1)
{
type_prompt();
read_command(command, parameters);
if(fork() != 0)
    wait(NULL);
else
{
strcpy(cmd, "/bin/");
strcat(cmd, command);

execve(cmd, parameters, envp);
for(j = 0; j < sizeof(*parameters); j++)
{
parameters[j] = NULL;
}
}
if(strcmp(cmd, "/bin/exit") == 0)
    break;

}
return 0;
}