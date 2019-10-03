#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).
*/

int	ft_is_space(char c)
{
	if (c == 32 || (c > 8 && c < 14))
		return (1);
	return (0);
}

int	length(char *s)
{
	int n;

	n = 0;
	while (*s++)
		n++;
	return (n);
}

void	ft_rev_words(char	*s)
{
	int	star;
	int	curr;

	star = length(s) - 1;
	while (star >= 0)
	{
		while (s[star] && !ft_is_space(s[star]))
			star--;
		star++;
		curr = star;
		while (s[curr] && !ft_is_space(s[curr]))
		{
			write(1, &s[curr], 1);
			curr++;
		}
		(star > 0) ? write(1, " ", 1) : write(0, "", 1);
		star -= 2;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_rev_words(av[1]);
	write(1, "\n", 1);
	return (0);
}