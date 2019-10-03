#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	char c;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] > 64 && av[1][i] < 91)
			{
				c = 'Z' - av[1][i] + 'A';
				write(1, &c, 1);
			}
			else if (av[1][i] > 96 && av[1][i] < 123)
			{
				c = 'z' - av[1][i] + 'a';
				write(1, &c, 1);
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}