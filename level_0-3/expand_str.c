/*
** Write a program that takes a string and displays it with exactly three spaces
** between each word, with no spaces or tabs either at the beginning or the end,
** followed by a newline.
** A word is a section of string delimited either by spaces/tabs, or by the
** start/end of the string.
** If the number of parameters is not 1, or if there are no words, simply display
** a newline.
*/

#include <unistd.h>

int ft_isspace(char c)
{
	return ((c == 32 || (c > 8 && c < 14)) ? 1 : 0);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		while (ft_isspace(*av[1]))
			av[1]++;
		while (*av[1])
		{
			if (ft_isspace(*av[1]))
			{
				while (ft_isspace(*av[1]))
					av[1]++;
				if (*av[1])
					write (1, "   ", 3);
			}
			if (*av[1])
			{
				write(1, av[1], 1);
				av[1]++;
			}
		}
	}
	write (1, "\n", 1);
	return (0);
}