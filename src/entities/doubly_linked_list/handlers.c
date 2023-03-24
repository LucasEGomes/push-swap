#include "doubly_linked_list.h"
#include <stddef.h>

int	connect_nodes_dl_list(t_dl_list *left, t_dl_list *right)
{
	if (left == NULL || right == NULL)
		return (1);
	right->prev = left;
	left->next = right;
	return (0);
}

void	replace_stack(t_dl_list *source, t_dl_list *destiny)
{
	t_dl_list	*head;

	head = source;
	while (source->next != head)
	{
		destiny->value = source->value;
		destiny = destiny->next;
		source = source->next;
	}
	destiny->value = source->value;
}

int	transform_into_circular_dl_list(t_dl_list *head)
{
	t_dl_list	*last;

	if (head == NULL)
		return (1);
	if (head->next == NULL)
		return (connect_nodes_dl_list(head, head));
	last = head->next;
	while (last->next != NULL)
	{
		if (last->next == head)
			return (1);
		last = last->next;
	}
	return (connect_nodes_dl_list(last, head));
}
