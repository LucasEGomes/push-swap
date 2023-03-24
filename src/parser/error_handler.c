#include "entities/doubly_linked_list/doubly_linked_list.h"
#include <stddef.h>

t_dl_list	*abort_parse(t_dl_list **node)
{
	delete_list_dl_list(node);
	return (NULL);
}
