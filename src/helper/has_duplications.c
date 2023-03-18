#include "entities/doubly_linked_list/doubly_linked_list.h"

int	has_duplications(t_dl_list *node)
{
	t_dl_list	*top;

	top = node;
	while (node->next != top)
	{
		if (node->value == node->next->value)
			return (1);
		node = node->next;
	}
	return (0);
}
