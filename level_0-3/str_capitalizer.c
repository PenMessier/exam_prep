/*
Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.
*/

#include <unistd.h>

void ft_strcap(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s > 64 && *s < 91)
			*s += 32;
		if ((*s > 96 && *s < 123) && (!*(s - 1) || *(s - 1) == 32 || (*(s - 1) > 8 && *(s - 1) < 14)))
			*s -= 32;
		write(1, s, 1);
		s++;
	}
	write (1, "\n", 1);
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 1)
	{
		while (i < ac)
		{
			ft_strcap(av[i]); 
			i++;
		}
	}
	else
		write (1, "\n", 1);
	return (0);
}