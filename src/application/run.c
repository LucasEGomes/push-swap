#include "application/application_internal.h"
#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include "entities/sorter_parameters/sorter_parameters.h"
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

static void	run_best_sorter(t_push_swap *orig_and_copy)
{
	t_sorter_params	range;
	t_sorter_params	step;

	if (orig_and_copy->size_a <= 8)
	{
		few_elements_sort(orig_and_copy, 1);
		return ;
	}
	set_sorter_params(&range, orig_and_copy->size_a / 2, 50, 0);
	if (orig_and_copy->size_a < 250)
		set_sorter_params(&step, 1, 1, 0);
	else if (orig_and_copy->size_a < 750)
		set_sorter_params(&step, 5, 5, 0);
	else
		set_sorter_params(&step, orig_and_copy->size_a / 5, 20, 0);
	optimize_sort_steps(orig_and_copy, range, step);
}

int	run_application(t_dl_list *stack_a)
{
	t_push_swap	orig_and_copy[2];
	t_push_swap	*copy;
	t_push_swap	*orig;

	orig = orig_and_copy + 0;
	copy = orig_and_copy + 1;
	initialize_push_swap(orig, stack_a);
	if (orig->size_a < 2)
		return (0);
	if (copy_push_swap(orig, copy))
		return (1);
	bubble_sort(copy, 0);
	if (has_duplications(copy->stack_a))
		return (free_application_resources(copy, 1));
	if (is_sorted(orig))
		return (free_application_resources(copy, 0));
	replace_with_index_push_swap(copy, orig);
	replace_stack(orig->stack_a, copy->stack_a);
	run_best_sorter(orig_and_copy);
	return (free_application_resources(copy, 0));
}
