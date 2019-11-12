#include <stdio.h>
#include <stdlib.h>

/*
Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there's one, will be valid.
*/

void	prime_factor(int	n)
{
	int p;

	p = 2;
	if (n == 1)
		printf("1");
	while (n > 1 || n >= p)
	{
		if (n % p == 0)
		{
			printf("%d", p);
			n /= p;
			if (n > 1)
			{
				printf("*");
				p--;
			}
		}
		p++;
	}
}

int	main(int ac, char **av)
{
	int	n;

	if (ac == 2)
	{
		n = atoi(av[1]);
		if (n && n > 0)
			prime_factor(n);
	}
	printf("\n");
	return (0);
}