#include "entities/push_swap/push_swap.h"
#include "entities/doubly_linked_list/doubly_linked_list.h"
#include <stddef.h>

void	initialize_push_swap(t_push_swap *push_swap, t_dl_list *stack_a)
{
	push_swap->stack_a = stack_a;
	push_swap->size_a = length_dl_list(stack_a);
	push_swap->stack_b = NULL;
	push_swap->size_b = 0;
}

int	copy_push_swap(t_push_swap *source, t_push_swap *destiny)
{
	int			index;
	t_dl_list	*node;
	t_dl_list	*source_node;

	destiny->size_a = source->size_a;
	destiny->size_b = source->size_b;
	if (source->stack_a != NULL)
	{
		source_node = source->stack_a;
		destiny->stack_a = new_node_dl_list(source_node->value);
		if (destiny->stack_a == NULL)
			return (1);
		node = destiny->stack_a;
		index = 1;
		while (index < source->size_a)
		{
			node->next = new_node_dl_list(source_node->value);
			if (node->next == NULL)
			{
				delete_list_dl_list(&(destiny->stack_a));
				return (1);
			}
			connect_nodes_dl_list(node, node->next);
			node = node->next;
			index++;
		}
	}
	if (source->stack_b == NULL)
		return (0);
	source_node = source->stack_b;
	destiny->stack_b = new_node_dl_list(source_node->value);
	if (destiny->stack_b == NULL)
	{
		delete_list_dl_list(&(destiny->stack_a));
		return (1);
	}
	node = destiny->stack_b;
	index = 1;
	while (index < source->size_b)
	{
		node->next = new_node_dl_list(source_node->value);
		if (node->next == NULL)
		{
			delete_list_dl_list(&(destiny->stack_a));
			delete_list_dl_list(&(destiny->stack_b));
			return (1);
		}
		connect_nodes_dl_list(node, node->next);
		node = node->next;
		index++;
	}
	return (0);
}