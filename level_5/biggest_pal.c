/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:01:56 by exam              #+#    #+#             */
/*   Updated: 2019/12/13 09:55:10 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_pal(char *s, int star, int end)
{
	int i;
	int f;

	i = 0;
	f = ((end - star + 1) % 2) ? 0 : 1;
	while (star + i != end - i - f)
	{
		if (s[star + i] == s[end - i])
			i++;
		else
			return (0);
	}
	if (f == 1 && s[star + i] == s[end - i])
		return (i * 2 + 2);
	else if (f == 0)
		return (i * 2 + 1);
	return (0);
}

int st_find(char *s, int *star, int *end)
{
	int i;
	int j;
	int l;
	int k;

	j = *end;
	i = *star;
	k = 0;
	l = 0;
	while (j > *star)
	{
		if (s[*star] == s[j] && (l = check_pal(s, *star, j)))
			break ;
		j--;
	}
	while (i < *end)
	{
		if (s[*end] == s[i] && (k = check_pal(s, i, *end)))
			break ;
		i++;
	}
	if (l >= k)
		*end = j;
	else if (k > l)
		*star = i;
	return ((l >= k) ? l : k);
}

void	find_all(char *s, int *end, int *star, int *l)
{
	int i;
	int a;
	int b;
	int c;
	int k;

	i = 1;
	c = 0;
	while (s[c])
		c++;
	c--;
	while (i <= (c + 1) / 2)
	{
		a = i;
		b = c - i;
		if ((k = st_find(s, &a, &b)) > *l)
		{
			*l = k;
			*star = a;
			*end = b;
		}
		i++;
	}
}

void	big_pal(char *s)
{
	int	star;
	int end;
	int l;

	star = 0;
	end = 0;
	while (s[end])
		end++;
	end--;
	if (star == end)
		l = 1;
	else
	{
		l = st_find(s, &star, &end);
		find_all(s, &end, &star, &l);
	}
	if (l)
	{
		while (star <= end)
		{
			write(1, &s[star], 1);
			star++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		big_pal(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
