/*
Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef	struct		s_list
{
	int				data;
	struct s_list	*next;
}					t_list;


void	new_list(t_list **begin, int d)
{
	t_list	*new;
	t_list	*curr;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return ;
	new->data = d;
	new->next = NULL;
	if (*begin == NULL)
	{
		*begin = new;
		return ;
	}
	curr = *begin;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	return ;
}

int		compare(int a, int b)
{
	if (a > b)
		return (0);
	else
		return (1);
}

void	swap(t_list *a, t_list *b)
{
	int	tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *begin;
	t_list *curr;

	begin = lst;
	if (!lst)
		return (0);
	while (lst)
	{
		curr = lst->next;
		while (curr)
		{
			if ((*cmp)(lst->data, curr->data) == 0)
				swap(lst, curr);
			curr = curr->next;
		}
		lst = lst->next;
	}
	return (begin);
}

void	print(t_list *start)
{
	t_list	*curr;
	int i;

	i = 6;
	curr = start;
	while (i >= 0 && curr->next != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
		i--;
	}
	printf("%d\n", curr->data);
}

int main()
{
	int 		a[7] = {4, 7, 1, 3, 2, 5, 6};
	t_list	*start;
	int i;

	i = 0;
	start = NULL;
	while (i < 7)
	{
		new_list(&start, a[i]);
		i++;
	}
	print(start);
	start = sort_list(start, compare);
	print(start);
	return (0);
}
