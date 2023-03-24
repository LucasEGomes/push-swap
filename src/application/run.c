#include "application/application_internal.h"
#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"
#include "sorters/bubble_sort/bubble_sort.h"
#include "sorters/few_elements_sort/few_elements_sort.h"
#include "sorters/merge_sort/merge_sort.h"
#include "helper/helper.h"
#include <stddef.h>

static int	free_application_resources(t_push_swap *push_swap, int return_code)
{
	delete_list_dl_list(&(push_swap->stack_a));
	delete_list_dl_list(&(push_swap->stack_b));
	return (return_code);
}

int	run_application(t_dl_list *stack_a)
{
	t_push_swap	auxiliary;
	t_push_swap	push_swap;

	initialize_push_swap(&push_swap, stack_a);
	if (push_swap.size_a < 2)
		return (0);
	if (copy_push_swap(&push_swap, &auxiliary))
		return (1);
	bubble_sort(&auxiliary, 0);
	if (has_duplications(auxiliary.stack_a))
		return (free_application_resources(&auxiliary, 1));
	if (is_sorted(&push_swap))
		return (free_application_resources(&auxiliary, 0));
	replace_with_index_push_swap(&auxiliary, &push_swap);
	replace_stack(push_swap.stack_a, auxiliary.stack_a);
	if (push_swap.size_a <= 8)
		few_elements_sort(&push_swap, 1);
	else
		optimize_sort_steps(&push_swap, &auxiliary);
	return (free_application_resources(&auxiliary, 0));
}
