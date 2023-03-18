#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"
#include "sorters/bubble_sort/bubble_sort.h"
#include "sorters/merge_sort/merge_sort.h"
#include <stddef.h>

int	start_application(t_dl_list *stack_a)
{
	t_push_swap	push_swap;
	t_push_swap	sorted;

	initialize_push_swap(&push_swap, stack_a);

	natural_merge_sort(&push_swap, 1);
	return (0);
}
