#include "doubly_linked_list.h"
#include <stddef.h>

int	length_dl_list(t_dl_list *head)
{
	t_dl_list	*first;
	int			size;

	if (head == NULL)
		return (0);
	if (head->next == NULL || head->next == head)
		return (1);
	first = head;
	size = 2;
	head = head->next;
	while (head->next != first && head->next != NULL)
	{
		size++;
		head = head->next;
	}
	return (size);
}
