/*
Displays the number of arguments.
*/

#include <unistd.h>

void	putnbr(int n)
{
	char s[10];
	int i;

	i = 0;
	while (n > 0)
	{
		s[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
		write(1, &s[i--], 1);
}

int main(int ac, char **av)
{
	av = 0;
	if (ac == 1)
		write(1, "0", 1);
	else
		putnbr((ac - 1));
	write(1, "\n", 1);
	return (0);
}