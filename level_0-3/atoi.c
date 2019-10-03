#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_atoi(const char *str)
{
	int i;
	int f;

	i = 0;
	f = 1;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
	{
		str++;
		f = -1;
	}
	else if (*str == '+')
		str++;
	while (*str > 47 && *str < 58)
	{
		i = 10 * i + *str - '0';
		str++;
	}
	return (i * f);
}

int main(void)
{
	char *s;

	s = "\t\v   -568830asdfnk";
	printf("%d\n", ft_atoi(s));
	printf("%d\n", atoi(s));
	return (0);
}