/*
Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
  void 					*data;
}								t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *curr;
	t_list *tmp;

	if (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		curr = *begin_list;
		*begin_list = (*begin_list)->next;
		free(curr);
	}
	curr = *begin_list;
	while (curr && curr->next != NULL)
	{
		if (cmp(curr->next->data, data_ref) == 0)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			free(tmp);
		}
		else
			curr = curr->next;
	}
}

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
	if (a < b)
		return (0);
	else
		return (1);
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

void	swap(t_list *a, t_list *b)
{
	int	tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

int				main()
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
	
	return (0);
}