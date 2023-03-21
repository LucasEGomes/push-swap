#include "entities/doubly_linked_list/doubly_linked_list.h"
#include <stddef.h>

int	get_distance(t_dl_list *node, int total, int value)
{
	int	index;

	if (node == NULL)
		return (0);
	if (node->next == node)
		return (0);
	index = 0;
	while ((value > node->value || value < node->prev->value)
		&& !(node->value < node->prev->value && value > node->prev->value)
		&& !(node->value < node->prev->value && value < node->value))
	{
		node = node->next;
		index++;
	}
	if (index > total / 2)
		return (index - total);
	return (index);
}
