#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int n;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		i -= 1;
		while (i && (av[1][i] == ' ' || av[1][i] == '\t'))
			i--;
		n = i;
		while (av[1][i] && av[1][i] != ' ')
			i--;
		i += 1;
		while (i <= n)
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}