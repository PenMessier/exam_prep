/*
Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_valid(char c, int str_base)
{
	char valid[17] = "0123456789abcdef";
	char valid1[17] = "0123456789ABCDEF";
	int i;

	i = 0;
	while (i < str_base)
	{
		if (c == valid[i] || c == valid1[i])
			return (1);
		i++;
	}
	return (0);
}

int get_power(int a, int power)
{
	int i;
	int r;

	i = 1;
	r = 1;
	if (power == 0)
		r = 1;
	while (i <= power)
	{
		r = r * a;
		i++;
	}
	return (r);
}

int value_n(char c)
{
	int n;

	n = 0;
	if (c >= '0' && c <= '9')
		n = c - '0';
	else if (c >= 97 && c <= 102)
		n = c - 'W';
	else if (c >= 65 && c <= 70)
		n = c - '7';
	return (n);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int r;
	int n[11];
	int s;
	int i;
	int j;

	r = 0;
	i = 0;
	j = 0;
	if (str_base < 2 && str_base > 16)
		return (0);
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	s = (*str == '-') ? -1 : 1;
	(*str == '+' || *str == '-') ? str++ : 0;
	while (*str && is_valid(*str, str_base))
	{
		n[i] = value_n(*str);
		i++;
		str++;
	}
	while (i >= 0)
		r = r + n[i-- - 1] * get_power(str_base, j++);
	return (r * s);
}

int main(int ac, char **av)
{
	int a;
	int b;

	if (ac == 3)
	{
		b = atoi(av[2]);
		a = ft_atoi_base(av[1], b);
		printf("%d\n", a);
	}
	return (0);
}