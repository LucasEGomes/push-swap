#include "doubly_linked_list.h"
#include <unistd.h>

int	append_node_dl_list(t_dl_list *node, t_dl_list *next)
{
	if (node == NULL || next == NULL)
		return (1);
	next->prev = node;
	node->next = next;
	return (0);
}
