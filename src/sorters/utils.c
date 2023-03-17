#include "application/application.h"

static int	count_ascending(t_dl_list *head, int size)
{
	int	index;

	index = 1;
	while (index <= size && head->value < head->next->value)
		index++;
	return (index);
}

static int	count_descending(t_dl_list *head, int size)
{
	int	index;

	index = 1;
	while (index <= size && head->value > head->next->value)
		index++;
	return (index);
}

int	get_group_size(t_dl_list *head, int size, int ascending)
{
	int	index;

	if (head == NULL)
		return (0);
	if (ascending)
		index = count_ascending(head, size);
	else
		index = count_descending(head, size);
	return (index);
}
