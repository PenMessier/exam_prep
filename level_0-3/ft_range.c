/*
Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		*ft_range(int start, int end)
{
	int *r;
	int n;
	int i;

	n = end - start;
	i = (n < 0) ? -1 : 1;
	n = (n < 0) ? -1 * n : n;
	r = (int *)malloc((n + 1) * sizeof(int));
	r[n] = end;
	while (n--)
	{
		r[n] = end - i;
		end -= i;
	}
	return (r);
}

int main(int ac, char **av)
{
	int a;
	int b;
	int *s;
	int n;
	int i;

	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		n = (a < b) ? (b - a) : (a - b);
		s = ft_range(a, b);
		for (i = 0; i <= n; i++)
			printf("%d ", s[i]);
		printf("\n");
	}
	return (0);
}