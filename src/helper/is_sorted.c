#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include <stddef.h>

int	is_sorted(t_push_swap *push_swap)
{
	t_dl_list	*node;
	int			index;

	if (push_swap->stack_b != NULL)
		return (0);
	index = 1;
	node = push_swap->stack_a;
	while (index < push_swap->size_a)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		index++;
	}
	return (1);
}
