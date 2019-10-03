/*
** Write a program that takes two strings representing two strictly positive
** integers that fit in an int.

** Display their highest common denominator followed by a newline (It's always a
** strictly positive integer).

** If the number of parameters is not 2, display a newline.
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int a;
	int b;
	int n;

	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		n = (a > b) ? b : a;
		while ((n > 0) && ((a % n) || (b % n)))
			n--;
		printf("%d", n);
	}
	printf("\n");
	return (0);
}