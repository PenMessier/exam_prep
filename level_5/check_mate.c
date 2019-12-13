/*
Write a program who takes rows of a chessboard in argument and check if your 
King is in a check position.

Chess is played on a chessboard, a squared board of 8-squares length with 
specific pieces on it : King, Queen, Bishop, Knight, Rook and Pawns.
For this exercice, you will only play with Pawns, Bishops, Rooks and Queen...
and obviously a King.

Each piece have a specific method of movement, and all patterns of capture are
detailled in the examples.txt file.

A piece can capture only the first ennemy piece it founds on its capture
patterns.

The board have a variable size but will remains a square. There's only one King
and all other pieces are against it. All other characters except those used for
pieces are considered as empty squares.

The King is considered as in a check position when an other enemy piece can
capture it. When it's the case, you will print "Success" on the standard output
followed by a newline, otherwise you will print "Fail" followed by a newline.

If there is no arguments, the program will only print a newline.

Examples:

$> ./chessmate '..' '.K' | cat -e
Fail$
$> ./check_mate 'R...' '.K..' '..P.' '....' | cat -e
Success$
$> ./chessmate 'R...' 'iheK' '....' 'jeiR' | cat -e
Success$
$> ./chessmate | cat -e
$
$>
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**create_map(int ac, char **av)
{
	char **s;
	int l;
	int i;
	int j;

	i = 0;
	l = 0;
	while (av[1][l])
		l++;
	if (l != ac - 1)
		return (0);
	if (!(s = (char **)malloc(sizeof(char *) * ac)))
		return (0);
	while (av[i + 1])
	{
		s[i] = (char *)malloc(sizeof(char) * (l + 1));
		j = 0;
		while (av[i + 1][j])
		{
			if (av[i + 1][j] == 'K' || av[i + 1][j] == 'P' || av[i + 1][j] == 'B'
			|| av[i + 1][j] == 'R' || av[i + 1][j] == 'Q')
				s[i][j] = av[i + 1][j];
			else
				s[i][j] = '.';
			j++;
		}
		i++;
	}
	s[i] = NULL;
	return (s);
}

void	print_map(char **s)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			write(1, &s[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int check_fig(int ac, char **av)
{
	int i;
	int l;

	i = 0;
	while (av[i + 1])
	{
		l = 0;
		while (av[i + 1][l])
			l++;
		if (l != ac - 1)
			return (0);
		i++;
	}
	return (l);
}

void	find_king(char **av, int *y, int *x)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 'K')
			{
				*y = i - 1;
				*x = j;
			}
			j++;
		}
		i++;
	}
}

int check_diag(char **av, int x, int y, int l)
{
	int i;

	i = 0;
	while (y + i < l && x + i < l)
	{
		if (av[y + i][x + i] == 'B' || av[y + i][x + i] == 'Q' ||  av[y + i][x + i] == 'P')
			return (1);
		i++;
	}
	i = 0;
	while (y + i < l && x - i >= 0)
	{
		if (av[y + i][x - i] == 'B' || av[y + i][x - i] == 'Q' || av[y + i][x - i] == 'P')
			return (1);
		i++;
	}
	i = 0;
	while (y - i >= 0 && x - i >= 0)
	{
		if (av[y - i][x - i] == 'B' || av[y - i][x - i] == 'Q')
			return (1);
		i++;
	}
	i = 0;
	while (y - i >= 0 && x + i < l)
	{
		if (av[y - 1][x + i] == 'B' || av[y - 1][x + i] == 'Q')
			return (1);
		i++;
	}
	return (0);
}

int check_line(char **av, int x, int y, int l)
{
	int i;

	i = 0;
	while (y - i >= 0)
	{
		if (av[y - i][x] == 'R' || av[y - i][x] == 'Q')
			return (1);
		i++;
	}
	i = 0;
	while (x + i < l)
	{
		if (av[y][x + i] == 'R' || av[y][x + i] == 'Q')
			return (1);
		i++;
	}
	i = 0;
	while (y + i < l)
	{
		if (av[y + i][x] == 'R' || av[y + i][x] == 'Q')
			return (0);
		i++;
	}
	i = 0;
	while (x - i >= 0)
	{
		if (av[y][x - i] == 'R' || av[y][x - i] == 'Q')
			return (1);
		i++;
	}
	return (0);
}

void	check_mate(char **av, int x, int y, int l)
{
	if (check_line(av, x, y, l) || check_diag(av, x, y, l))
		write(1, "Success", 7);
	else
		write(1, "Fail", 4);
}

int main(int ac, char **av)
{
	char **s;
	int x;
	int y;
	int l;

	if (ac > 1)
	{
		if ((l = check_fig(ac, av)))
		{
			find_king(av, &y, &x);
			check_mate(av, x, y, l);
			write (1, "\n", 1);
			s = create_map(ac, av);
			print_map(s);
		}
	}
	write (1, "\n", 1);
	return (0);
}
