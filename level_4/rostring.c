#include <unistd.h>

/*
Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.
*/

int	is_space(char c)
{
	if (c == 32 || (c > 8 && c < 14))
		return (1);
	return (0); 
}

void	print_str(char *s)
{
	while (*s)
	{
		if (*s && !is_space(*s))
			write(1, s, 1);
		if (is_space(*s) && *(s + 1) && !is_space(*(s + 1)))
			write(1, " ", 1);
		s++;
	}
	write(1, " ", 1);
}

void	read_first(char *s)
{
	while (*s && is_space(*s))
		s++;
	while (*s && !is_space(*s))
	{
		write(1, s, 1);
		s++;
	}
}

void	rostr(char *s)
{
	while (*s && is_space(*s))
		s++;
	while (*s && !is_space(*s))
		s++;
	while (*s && is_space(*s))
		s++;
	if (*s)
		print_str(s);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		rostr(av[1]);
		read_first(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
