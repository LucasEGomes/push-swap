#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include "entities/sorter_parameters/sorter_parameters.h"
#include "operations/operations.h"
#include "sorters/bubble_sort/bubble_sort.h"
#include "sorters/few_elements_sort/few_elements_sort.h"
#include "sorters/merge_sort/merge_sort.h"
#include "helper/helper.h"
#include <stddef.h>
#include <stdio.h>

static int	apply_offset(t_push_swap *push_swap, int offset, int verbose)
{
	int	steps;

	if (offset > 0)
	{
		steps = offset;
		while (offset-- > 0)
			reverse_rotate_a(push_swap, verbose);
		return (steps);
	}
	steps = -offset;
	while (offset++ < 0)
		rotate_a(push_swap, verbose);
	return (steps);
}

static int	apply_rate(t_push_swap *push_swap, int rate, int verbose)
{
	int	pushes;

	pushes = rate * push_swap->size_a / 100;
	return (split_stack_a(push_swap, pushes, verbose));
}

static int	setup(t_push_swap *push_swap, int offset, int rate, int verbose)
{
	int	steps;

	steps = 0;
	steps += apply_offset(push_swap, offset, verbose);
	if (push_swap->stack_a->value > push_swap->stack_a->next->value)
		steps += swap_a(push_swap, verbose);
	steps += apply_rate(push_swap, rate, verbose);
	if (push_swap->size_a > 1
		&& push_swap->stack_a->value > push_swap->stack_a->next->value)
		steps += swap_a(push_swap, verbose);
	return (steps);
}

static void	run_iteration(t_push_swap *orig_and_copy, t_sorter_params *params,
	t_sorter_params *best_params, int verbose)
{
	t_push_swap	*copy;
	t_push_swap	*orig;

	orig = orig_and_copy;
	copy = orig_and_copy + 1;
	replace_stack(orig->stack_a, copy->stack_a);
	params->steps = setup(copy, params->offset, params->rate, verbose);
	params->steps += natural_merge_sort(copy, verbose);
	if (params->steps < best_params->steps)
		copy_sorter_params(params, best_params);
}

void	optimize_sort_steps(t_push_swap *orig_and_copy, t_sorter_params range,
	t_sorter_params step)
{
	t_sorter_params	best_params;
	t_sorter_params	params;

	set_sorter_params(&best_params, __INT_MAX__, __INT_MAX__, __INT_MAX__);
	params.offset = -range.offset;
	while (params.offset <= range.offset)
	{
		params.rate = -range.rate;
		while (params.rate <= range.rate)
		{
			run_iteration(orig_and_copy, &params, &best_params, 0);
			params.rate += step.rate;
		}
		params.offset += step.offset;
	}
	run_iteration(orig_and_copy, &best_params, &best_params, 1);
}
