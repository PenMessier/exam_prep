/*
** Write a program named hidenp that takes two strings and displays 1
** followed by a newline if the first string is hidden in the second one,
** otherwise displays 0 followed by a newline.
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int hidenp(char *need, char *hay)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (need[i])
		i++;
	while (*hay)
	{
		if (need[j] == *hay)
			j++;
		hay++;
	}
	if (i == j)
		return (1);
	else
		return (0);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		if (hidenp(av[1], av[2]) == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}