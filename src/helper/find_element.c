#include "entities/doubly_linked_list/doubly_linked_list.h"

int	find_element(t_dl_list *head, int total, int value)
{
	t_dl_list	*node;
	int	index;

	index = 0;
	node = head;
	while (node->value != value)
	{
		node = node->next;
		index++;
	}
	if (index > total / 2)
		return (index - total);
	return (index);
}
