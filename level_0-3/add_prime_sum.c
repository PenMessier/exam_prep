#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *s)
{
	int i;

	i = 0;
	while (*s == 32 || (*s > 8 && *s < 13))
		s++;
	if (*s == '-')
		return (0);
	if (*s == '+')
		s++;
	while (*s > 47 && *s < 58)
	{
		i = 10 * i + *s - '0';
		s++;
	}
	return (i);
}

int ft_isprime(int n)
{
	int i;

	i = 2;
	if (n < i)
		return (0);
	if (n == 2)
		return (1);
	while (i < n)
	{
		if (!(n % i))
			return (0);
		i++;
	}
	return(1);
}

void ft_putnbr(int n)
{
	char str[10];
	int i;
	char c;

	i = 0;
	while (n > 9)
	{
		str[i] = n % 10;
		n = n / 10;
		i++;
	}
	if (n < 10)
		str[i] = n;
	while (i >= 0)
	{
		c = str[i] + '0';
		write (1, &c, 1);
		i--;
	}
}

int main(int ac, char **av)
{
	int n;
	int i;
	int count;

	i = 1;
	count = 0;
	if (ac == 2)
	{
		if ((n = ft_atoi(av[1]))!= 0)
		{
			while (i <= n)
			{
				if (ft_isprime(i))
					count += i;
				i++;
			}
			ft_putnbr(count);
		}
		else
			write(1, "0", 1);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}