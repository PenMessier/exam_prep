/* 
Write a program that takes an undefined number of strings in arguments. For each
argument, the program prints on the standard output "OK" followed by a newline 
if the expression is correctly bracketed, otherwise it prints "Error" followed by
a newline.

Symbols considered as 'brackets' are brackets '(' and ')', square brackets '[' 
and ']'and braces '{' and '}'. Every other symbols are simply ignored.

An opening bracket must always be closed by the good closing bracket in the 
correct order. A string which not contains any bracket is considered as a 
correctly bracketed string.

If there is no arguments, the program must print only a newline.

Examples :

$> ./brackets '(johndoe)' | cat -e
OK$
$> ./brackets '([)]' | cat -e
Error$
$> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e
OK$
OK$
$> ./brackets | cat -e
$
*/

#include <unistd.h>
#include <stdio.h>

int	is_bracket(char c)
{
	if (c == '(' || c == '{' ||  c == '[')
		return (1);
	if (c == ')' || c == '}' || c == ']')
		return (2);
	return (0);
}

int br_check(char a, char b)
{
	if ((b == ')' && a == '(') || (b == '}' && a == '{')
		|| (b == ']' && a == '['))
		return (1);
	if (a == ')' || a == '}' || a == ']')
		return (1);
	return (0);
}

int	str_check(char *s)
{
	int a;
	int b;
	int c;
	int i;
	int j;

	a = 0;
	b = 0;
	c = 0;
	i = 0;
	while (s[i])
	{
		if (is_bracket(s[i]) == 1)
		{
			(s[i] == '(') ? a++ : 0;
			(s[i] == '{') ? b++ : 0;
			(s[i] == '[') ? c++ : 0;
		}
		if (is_bracket(s[i]) == 2)
		{
			j = i - 1;
			while (s[j] && !is_bracket(s[j]))
				j--;
			if (!s[j] || !br_check(s[j], s[i]))
				return (0);
			(s[i] == ')') ? a-- : 0;
			(s[i] == '}') ? b-- : 0;
			(s[i] == ']') ? c-- : 0;
		}
		i++;
	}
	return ((!a && !b && !c) ? 1 : 0);
}

void	brackets(char *s)
{
	if (str_check(s))
		write (1, "OK\n", 3);
	else
		write (1, "Error\n", 6);
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			brackets(av[i]);
			i++;
		}
	}
	else
		write (1, "\n", 1);
	return (0);
}
