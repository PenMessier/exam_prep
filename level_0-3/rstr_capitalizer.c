/*
** Write a program that takes one or more strings and, for each argument, puts 
** the last character of each word (if it's a letter) in uppercase and the rest
** in lowercase, then displays the result followed by a \n.
** A word is a section of string delimited by spaces/tabs or the start/end of the
** string. If a word has a single letter, it must be capitalized.
** If there are no parameters, display \n.
*/

#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] > 64 && av[i][j] < 91)
					av[i][j] += 32;
				if ((av[i][j] > 96 && av[i][j] < 123) && (av[i][j + 1] == 32
				 || (av[i][j + 1] > 8 && av[i][j + 1] < 14) || !av[i][j + 1]))
					av[i][j] -= 32;
				write(1, &av[i][j], 1);
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}