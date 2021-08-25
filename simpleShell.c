#include "simishell.h"

/**
 * main - The main function
 * @argc: Argument counter
 * @argv: Array of parameters
 * Return: 0
 */

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
int i = 0;
char *line;
line = malloc(256);

description();
printf("\n");

do {
i = 0;

if (getstr(line) == (-1))
{
perror("Error");
exit(1);
}

if (shellprocessor(strbrk(line)) == -1)
{
perror("Error");
}
} while (1);
return (0);
}
