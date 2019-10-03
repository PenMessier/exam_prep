#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	int i;
	int r;

	i = 1;
	r = 1;
	while (r < (int)n)
	{
		r = r * 2;
		i++;
	}
	return ((r == (int)n) ? 1 : 0);
}

int main(int ac, char **av)
{
	unsigned int b;

	if(ac == 2)
	{
		b = (unsigned int)atoi(av[1]);
		printf("%d\n", is_power_of_2(b));
	}
	return (0);
}