#include <stdio.h>
#include <stdlib.h>

/*
Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

int	ft_is_space(char c)
{
	if (c == 32 || (c > 8 && c < 14))
		return (1);
	return (0);
}

int count_words(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		while (*s && ft_is_space(*s))
			s++;
		if (*s && !ft_is_space(*s))
		{
			i++;
			while (*s && !ft_is_space(*s))
				s++;
		}
	}
	return (i);
}

int	count_letters(char *s)
{
	int i;

	i = 0;
	while (*s && ft_is_space(*s))
		s++;
	while (*s && !ft_is_space(*s))
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_split(char *str)
{
	char **s;
	int n;
	int i;
	int j;

	n = count_words(str);
	j = 0;
	s = (char **)malloc(sizeof(char *) * n);
	while (j <= n)
	{
		i = 0;
		s[j] = (char *)malloc(sizeof(char) * (count_letters(str) + 1));
		while (*str && ft_is_space(*str))
			str++;
		while (*str && !ft_is_space(*str))
		{
			s[j][i] = *str;
			str++;
			i++;
		}
		s[j][i] = '\0';
		j++;
	}
	s[j] = NULL;
	return (s);
}

int main(int ac, char **av)
{
	char **s;
	int i;

	i = 0;
	if (ac == 2)
	{
		s = ft_split(av[1]);
		while (**s)
		{
			printf("%s\n", *s);
			s++;
		}
	}
	return (0);
}