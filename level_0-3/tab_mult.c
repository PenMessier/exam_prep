/*
Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.
*/

#include <unistd.h>

int ft_atoi(char *s)
{
	long n;

	n = 0;
	while (*s > 47 && *s < 58)
		n = n * 10 + *s++ - '0';
	return((int)n);
}

void putnbr(int a)
{
	char s[10];
	int i;

	i = 0;
	while (a > 0)
	{
		s[i] = a % 10 + '0';
		i++;
		a /= 10;
	}
	i--;
	while (i >= 0)
		write (1, &s[i--], 1);
}

void	tab_mult(int a)
{
	int i;
	int c;

	i = 1;
	while (i <= 9)
	{
		c = i + '0';
		write (1, &c, 1);
		write (1, " x ", 3);
		putnbr(a);
		write (1, " = ", 3);
		putnbr(a * i);
		write (1, "\n", 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int a;

	if (ac == 2)
	{
		a = ft_atoi(av[1]);
		tab_mult(a);
	}
	else
		write (1, "\n", 1);
	return (0);
}