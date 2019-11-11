/*
Write a program that takes a string which contains an equation written in
Reverse Polish notation (RPN) as its first argument, evaluates the equation, and
prints the result on the standard output followed by a newline. 

Reverse Polish Notation is a mathematical notation in which every operator
follows all of its operands. In RPN, every operator encountered evaluates the
previous 2 operands, and the result of this operation then becomes the first of
the two operands for the subsequent operator. Operands and operators must be
spaced by at least one space.

You must implement the following operators : "+", "-", "*", "/", and "%".

If the string isn't valid or there isn't exactly one argument, you must print
"Error" on the standard output followed by a newline.

All the given operands must fit in a "int".

Examples of formulas converted in RPN:

3 + 4                   >>    3 4 +
((1 * 2) * 3) - 4       >>    1 2 * 3 * 4 -  ou  3 1 2 * * 4 -
50 * (5 - (10 / 9))     >>    5 10 9 / - 50 *

Examples:

$> ./rpn_calc "1 2 * 3 * 4 +" | cat -e
10$
$> ./rpn_calc "1 2 3 4 +" | cat -e
Error$
$> ./rpn_calc |cat -e
Error$
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	is_space(char c)
{
	return ((c == 32 || (c > 8 && c< 13)) ? 1: 0);
}

int is_oper(char c)
{
	if (c == '+' || c == '-' || c == '*'
	|| c == '/' || c == '%')
		return (1);
	return (0);
}

int is_num(char *s, int *i, int *n)
{
	if ((s[*i] == '-' || s[*i] == '+') &&
		(s[*i + 1] > 47 && s[*i + 1] < 58))
		*i += 1;
	if (s[*i] > 47 && s[*i] < 58)
	{
		//printf("s[%d] = %c\n", *i, s[*i]);
		while (s[*i] && !(is_space(s[*i])))
			*i += 1;
		(!s[*i]) ? *i -= 1 : 0;
		*n += 1;
		//printf("n = %d\n", *n);
		return (1);
	}
	return (0);
}

int calc(int a, int b, char o)
{
	if (o == '+')
		return (a + b);
	if (o == '-')
		return (a - b);
	if (o == '*')
		return (a * b);
	if (o == '/' && b != 0)
		return (a / b);
	if (o == '%' && b != 0)
		return (a % b);
	return (0);
}

int check_str(char *s)
{
	int i;
	int o;
	int n;

	i = 0;
	o = 0;
	n = 0;
	while (s[i])
	{
		if (!is_num(s, &i, &n) && !is_space(s[i]) && !is_oper(s[i]))
			return (0);
		(is_oper(s[i])) ? o++ : 0;
		i++;
	}
	i--;
	while (is_space(s[i]))
		i--;
	if (o != 0 && (s[i] > 47 && s[i] < 58))
		return (0);
	return ((n == o + 1) ? 1 : 0);
}

int find_number(char *s, int *i, int op, int *f)
{
	int n;

	while (s[*i] && is_space(s[*i]))
		*i -= 1;
	if (*i < 0)
		*f = 1;
	if (*f == 1)
	{
		*i = op - 1;
		while (s[*i] && is_space(s[*i]))
			*i -= 1;
		if (s[*i] < 48 || s[*i] > 57)
		{
			*f = -1;
			return (0);
		}
	}
	while (s[*i] && !is_space(s[*i]))
		*i -= 1;
	*i += 1;
	n = atoi(&s[*i]);
	*i -= 1;
	return (n);
}

int	rpn_calc(char *s, int *in, int *op, int *n, int *f)
{
	int i;
	int e;
	int a;

	i = 0;
	e = 0;
	a = find_number(s, in, *op, f);
	if (*f == -1)
		return (-1);
	*n = calc(a, *n, s[*op]);
	if (*n == 0 && (s[*op] == '/' || s[*op] == '%'))
	{
		printf("check\n");
		return (-1);
	}
	*op += 1;
	while (s[*op] && !is_oper(s[*op]))
		*op += 1;
	if (s[*op] && is_oper(s[*op]))
		rpn_calc(s, in, op, n, f);
	return (1);
}

int main(int ac, char **av)
{
	int n;
	int i;
	int o;
	int f;

	n = 0;
	f = 0;
	i = 0;
	if (ac == 2)
	{
		if (!check_str(av[1]))
		{
			printf("Error\n");
			return (0);
		}
		while (av[1][i] && !is_oper(av[1][i]))
			i++;
		if (!av[1][i])
		{
			printf("%s\n", av[1]);
			return (0);
		}
		o = i;
		i--;
		n = find_number(av[1], &i, o, &f);
		if (f == -1)
		{
			printf("%s\n", av[1]);
			return (0);
		}
		if (rpn_calc(av[1], &i, &o, &n, &f) == -1)
		{
			printf("Error\n");
			return (0);
		}
		printf("%d\n", n);
	}
	else
		printf("Error\n");
	return (0);
}
