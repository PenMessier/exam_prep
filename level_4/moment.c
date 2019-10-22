#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int			convert(unsigned int n, int *f)
{
	if (n < 60)
		*f = 6;//second
	else if (n > 59 && n < 3600)
	{
		n /= 60;
		*f = 7;//minuite
	}
	else if (n > 3599 && n < 3600 * 24)
	{
		n /= 3600;
		*f = 4;//hour
	}
	else if (n > (3600 * 24 - 1) && n < 3600 * 24 * 30)
	{
		n /= (3600 * 24);
		*f = 3;//day
	}
	else
		n /= (3600 * 24 * 30);//month
	return ((int)n);
}

char		*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char		*ft_intcpy(char *dest, int n)
{
	int		i;
	char	s[11];

	i = 0;
	while (n > 9)
	{
		s[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	s[i] = n + '0';
	while (i >= 0)
	{
		*dest = s[i];
		dest++;
		i--;
	}
	return (dest);
}

char		*choose_str(char *d, int f, int n)
{
	if (f == 6)
		d = (n == 1) ? ft_strcpy(d, " second") : ft_strcpy(d, " seconds");
	else if (f == 7)
		d = (n == 1) ? ft_strcpy(d, " minute") : ft_strcpy(d, " minutes");
	else if (f == 4)
		d = (n == 1) ? ft_strcpy(d, " hour") : ft_strcpy(d, " hours");
	else if (f == 3)
		d = (n == 1) ? ft_strcpy(d, " day") : ft_strcpy(d, " days");
	else
		d = (n == 1) ? ft_strcpy(d, " month") : ft_strcpy(d, " months");
	return (d);
}

char		*moment(unsigned int duration)
{
	char	*s;
	int		f;
	int		n;
	int		r;
	int		i;

	f = 5;//month
	n = convert(duration, &f);
	r = n;
	i = 1;
	while (r > 9)
	{
		i++;
		r /= 10;
	}
	i = (n == 1 || f == 7) ? i : i + 1;
	s = (char *)malloc(sizeof(char) * (i + f + 7));
	if (!s)
		return(0);
	*ft_strcpy(choose_str(ft_intcpy(s, n), f, n), " ago.") = '\0';
	return (s);
}

int			main(int ac, char **av)
{
	int		a;
	char	*s;

	if (ac == 2)
	{
		a = atoi(av[1]);
		s = moment((unsigned int)a);
		printf("%s\n", s);
	}
	return (0);
}
