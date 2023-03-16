#include "doubly_linked_list.h"
#include <stdlib.h>

void	delete_node_dl_list(t_dl_list *node)
{
	node->value = 0;
	node->next = NULL;
	node->prev = NULL;
	free(node);
}
