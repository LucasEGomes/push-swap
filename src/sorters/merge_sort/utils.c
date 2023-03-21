#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "operations/operations.h"
#include <stddef.h>

static int	count_ascending(t_dl_list *head, int limit, int from_top)
{
	int	index;

	index = 0;
	if (from_top)
	{
		while (index++ <= limit && head->value < head->next->value)
			head = head->next;
		return (index);
	}
	while (index++ <= limit && head->prev->value > head->prev->prev->value)
		head = head->prev;
	return (index);
}

static int	count_descending(t_dl_list *head, int limit, int from_top)
{
	int	index;

	index = 0;
	if (from_top)
	{
		while (index++ <= limit && head->value > head->next->value)
			head = head->next;
		return (index);
	}
	while (index++ <= limit && head->prev->value < head->prev->prev->value)
		head = head->prev;
	return (index);
}

int	get_group_size(t_dl_list *head, int limit, int ascending, int from_top)
{
	int	index;

	if (head == NULL)
		return (0);
	if (ascending)
		index = count_ascending(head, limit, from_top);
	else
		index = count_descending(head, limit, from_top);
	return (index);
}
