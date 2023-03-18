#include "doubly_linked_list/doubly_linked_list.h"
#include "merge_sort.h"

int	is_single_group(t_dl_list *node, int size)
{
	return (get_group_size(node, size, 1, 1) == size);
}
