#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include <stddef.h>

static void	push(t_dl_list **source, t_dl_list **destiny)
{
	t_dl_list	*new_head;

	new_head = (*source)->next;
	if (new_head == *source)
		new_head = NULL;
	connect_nodes_dl_list((*source)->prev, (*source)->next);
	if (*destiny != NULL)
	{
		connect_nodes_dl_list((*destiny)->prev, *source);
		connect_nodes_dl_list(*source, *destiny);
		*destiny = *source;
		*source = new_head;
		return ;
	}
	*destiny = *source;
	*source = new_head;
	connect_nodes_dl_list(*destiny, *destiny);
}

int	push_a(t_push_swap *push_swap, int verbose)
{
	if (push_swap->size_b > 0)
	{
		push(&(push_swap->stack_b), &(push_swap->stack_a));
		push_swap->size_a++;
		push_swap->size_b--;
	}
	if (verbose)
		write(STDOUT_FILENO, "pa\n", 3);
	return (1);
}

int	push_b(t_push_swap *push_swap, int verbose)
{
	if (push_swap->size_a > 0)
	{
		push(&(push_swap->stack_a), &(push_swap->stack_b));
		push_swap->size_a--;
		push_swap->size_b++;
	}
	if (verbose)
		write(STDOUT_FILENO, "pb\n", 3);
	return (1);
}
