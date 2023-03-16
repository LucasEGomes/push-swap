#include "doubly_linked_list.h"
#include <stdlib.h>

t_dl_list	*new_node_dl_list(int value)
{
	t_dl_list	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
