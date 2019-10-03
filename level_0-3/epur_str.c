/*
** Write a program that takes a string, and displays this string with exactly one
** space between words, with no spaces or tabs either at the beginning or the end,
** followed by a \n.
*/
#include <unistd.h>
#include <stdio.h>
int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] == 32 || (av[1][i] > 8 && av[1][i] < 14))
			i++;
		while (av[1][i])
		{
			while (av[1][i] == 32 || (av[1][i] > 8 && av[1][i] < 14))
			{
				if (av[1][i + 1] && (av[1][i + 1] != 32 || (av[1][i + 1] < 9 && av[1][i + 1] > 13)))
					write(1, &av[1][i], 1);
				i++;
			}
			if (av[1][i])
			{
				write(1, &av[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}