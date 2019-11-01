#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
Write a function that takes a char ** as a 2-dimensional array of char, a
t_point as the dimensions of this array and a t_point as the starting point.
Starting from the given 'begin' t_point, this function 'colors' an entire zone
by replacing characters inside by the character 'F'. A zone is an ensemble of
the same character delimitated horizontally and vertically by other characters.
The flood_fill function won't 'color' in diagonal.
The flood_fill function will be prototyped like this:
void  flood_fill(char **tab, t_point size, t_point begin);
The t_point structure is available inside the "t_point.h" file attached to this
assignment. We will use our "t_point.h" for graduation.
*/
#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

typedef struct	s_point {
	int						x;
	int						y;
}								t_point;

#endif

char **make_area(char **zone, t_point size)
{
	int x;
	int	y;
	int i;
	int j;
	char **area;

	y = size.y;
	x = size.x;
	i = 0;
	area = (char **)malloc(sizeof(char *) * y + 1);
	if (!area)
		return (0);
	while (i < y)
	{
		area[i] = (char *)malloc(sizeof(char) * x + 1);
		j = 0;
		while (j < x)
		{
			area[i][j] = zone[i][j];
			j++;
		}
		area[i][j] = '\0';
		i++;
	}
	area[y] = NULL;
	return (area);
}

void	print_area(char **area)
{
	int x;
	int y;

	y = 0;
	while (area[y])
	{
		x = 0;
		while (area[y][x])
		{
			write(1, &area[y][x], 1);
			write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int check_point(t_point new, t_point size)
{
	int x;
	int y;

	x = new.x;
	y = new.y;
	if (x >= 0 && y >= 0 && x < size.x && y < size.y)
		return (1);
	return (0);
}

t_point	make_point(int x, int y)
{
	t_point new;

	new.x = x;
	new.y = y;
	return (new);
}

void	flood(char **area, t_point begin, t_point size, char b)
{
	int x;
	int y;

	x = begin.x;
	y = size.y - 1 - begin.y;
	if (check_point(begin, size) && area[y][x] == b)
	{
		area[y][x] = 'F';
		flood(area, make_point(x + 1, begin.y), size, b);
		flood(area, make_point(x - 1, begin.y), size, b);
		flood(area, make_point(x, begin.y + 1), size, b);
		flood(area, make_point(x, begin.y - 1), size, b);
	}
}

void  flood_fill(char **area, t_point size, t_point begin)
{
	char b;

	b = area[size.y - 1 - begin.y][begin.x];
	flood(area, begin, size, b);
}

int	main()
{
	char **area;
	t_point size = { 8, 5 };
	t_point begin = { 2, 2 };
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001"
	};
	area = make_area(zone, size);
	print_area(area);
	write(1, "\n", 1);
	flood_fill(area, size, begin);
	print_area(area);
	return (0);
}