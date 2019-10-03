/*
Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	char *s;
	int i;
	int n;

	i = (nbr < 0) ? 2 : 1;
	if (nbr == -2147483648)
		n = 2147483647;
	else
		n = (nbr < 0) ? -1 * nbr : nbr;
	while ((n /= 10) >= 1)
		i++;
	n = (nbr < 0) ? -1 : 1;
	if (nbr == -2147483648)
	{
		n = -2;
		nbr = 2147483647;
	}
	else
		nbr = nbr * n;
	s = (char *)malloc(i * sizeof(char) + 1);
	s[i--] = '\0';
	while (nbr)
	{
		s[i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	s[0] = (n < 0) ? '-' : s[0];
	s[10] = (n == -2) ? '8' : ' ';
	return (s);
}

int main(int ac, char **av)
{
	int n;
	char *s;

	if (ac == 2)
	{
		n = atoi(av[1]);
		s = ft_itoa(n);
		printf("%s\n", s);
	}
	return (0);
}