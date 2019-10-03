#include <unistd.h>
#include <stdio.h>
#include <string.h>

/*
Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

void	swap(int a,  int b, int *tab)
{
	int	c;

	c = tab[a];
	tab[a] = tab[b];
	tab[b] = c;
}

void sort_int_tab(int *tab, unsigned int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)size)
	{
		j = 0;
		while (j < (int)size - 1)
		{
			if (tab[j] > tab[j + 1])
				swap(j, j + 1, tab);
			j++;
		}
		i++;
	}
}

int	main()
{
	int tab[12] = {12, 2, 6, 9, 1, 5, 3, 0};
	unsigned int size = 6;
	int	i;

	i = 0;
	sort_int_tab(tab, size);
	while (i < (int)size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}