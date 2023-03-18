#include "application/application.h"
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

int	find_element(t_dl_list *node, int total, int value)
{
	int	index;

	index = 0;
	while (node->value != value)
	{
		node = node->next;
		index++;
	}
	if (index > total / 2)
		return (index - total);
	return (index);
}
