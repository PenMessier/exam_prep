/*
** Write a program that takes a positive (or zero) number expressed in base 10,
** and displays it in base 16 (lowercase letters) followed by a newline.

** If the number of parameters is not 1, the program displays a newline.
*/

#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *s)
{
	long n;
	int f;

	n = 0;
	while (*s == 32 || (*s > 8 && *s < 14))
		s++;
	f = (*s == '-') ? -1 : 1;
	(*s == '-' || *s == '+') ? s++ : s;
	while (*s >= '0' && *s <= '9')
		n = n * 10 + *s++ - '0';
	return ((int)n * f);
}

void get_hex(int n)
{
	int s[12];
	char c;
	int i;

	i = 0;
	while (n > 15)
	{
		s[i] = n % 16;
		n = n / 16;
		i++;
	}
	s[i] = n;
	while (i >= 0)
	{
		if (s[i] >= 0 && s[i] <= 9)
			c = s[i] + '0';
		if (s[i] > 9 && s[i] < 16)
			c = s[i] + 'W';
		write (1, &c, 1);
		i--;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		get_hex(ft_atoi(av[1]));
	write (1, "\n", 1);
	return (0);
}