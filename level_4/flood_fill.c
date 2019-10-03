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

char **tab_dup(char **tab, int h)
{
	int i;
	int	j;
	char **ret;

	i = 0;
	j = 0;
	ret = (char **)malloc(sizeof(char *) * h);
	while (i < h)
	{
		if (i % 5 == 0)
			j = 0;
		ret[i] = strdup(tab[j]);
		j++;
		i++;
	}
	return ret;
}

void	print_tab(char **tab, int size)
{
	int	y;

	y = 0;
	while (y < size)
	{
		printf("%s", tab[y]);
		printf("\n");
		y++;
	}
	printf("\n");
}

void	flood(char **tab, t_point begin, t_point size, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (x > size.x || y > size.y)
		return ;
	if (x < begin.x && y < begin.x)
		return ;
	//if (tab[x][y] != b)
	//	return ;
	tab[x][y] = 'F';
	flood(tab, begin, size, x + 1, y);
	flood(tab, begin, size, x - 1, y);
	flood(tab, begin, size, x, y + 1);
	flood(tab, begin, size, x, y - 1);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	flood(tab, begin, size, begin.x, begin.y);
}

int	main()
{
	t_point size = { 8, 5 };
	t_point begin = { 2, 2 };
	char *area[5];
	area[0] = "11111111";
	area[1] = "10001001";
	area[2] = "10010001";
	area[3] = "10010001";
	area[4] = "11100001";

	char **map = tab_dup(area, 10);
	//print_tab(map, 10);
	flood_fill(map, size, begin);
	print_tab(map, 10);
	return (0);
}