/*
** Write a function that returns the number of elements in the linked list that's
** passed to it.
 */

#include <unistd.h>
#include <stdio.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	int i;
	t_list *curr;

	i = 0;
	curr = begin_list;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}