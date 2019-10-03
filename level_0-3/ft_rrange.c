/*
** Write the following function:
** int     *ft_rrange(int start, int end);
** It must allocate (with malloc()) an array of integers, fill it with consecutive
** values that begin at end and end at start (Including start and end !), then
** return a pointer to the first value of the array.
*/

#include <stdio.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int *s;
	int n;
	int i;

	n = end - start;
	if (n < 0)
		n *= -1;
	if (start > end)
		i = -1;
	else
		i = 1;
	s = (int *)malloc((n + 1) * sizeof(int));
	s[n] = start;
	while (n--)
	{
		s[n] = start + i;
		start += i;
	}
	s[0] = end;
	return (s);
}

int main(int ac, char **av)
{
	int *s;
	int i;
	int a;
	int b;
	int n;

	i = 0;
	a = atoi(av[1]);
	b = atoi(av[2]);
	if (ac == 3)
	{
		s = ft_rrange(a, b);
		n = a - b;
		if (n < 0)
			n *= -1;
		for (i = 0; i <= n; i++)
		{
			printf("%d ", s[i]);
		}
	}
	return (0);
}