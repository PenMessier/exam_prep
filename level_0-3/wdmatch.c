#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[1][i])
			i++;
		while (*av[2] && j < i)
		{
			if (av[1][j] == *av[2])
				j++;
			av[2]++;
		}
		if (i == j)
			write(1, av[1], i);
	}
	write(1, "\n", 1);
	return (0);
}