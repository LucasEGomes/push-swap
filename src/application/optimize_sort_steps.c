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
	if (push_swap->stack_a->value > push_swap->stack_a->next->value)
		steps += swap_a(push_swap, verbose);
	return (steps);
}

static void	run_iteration(t_sorter_params *params, t_sorter_params *best_params)
{
	replace_stack(original->stack_a, push_swap->stack_a);
	params->steps = setup(push_swap, params->offset, params->rate, 0);
	params->steps += natural_merge_sort(push_swap, 0);
	if (params->steps < best_params->steps)
		copy_sorter_params(params, best_params);
}

void	optimize_sort_steps(t_push_swap *push_swap, t_push_swap *original)
{
	int				offset_limit;
	t_sorter_params	params;
	t_sorter_params	best_params;

	params.offset = OFFSET_LOWER_LIMIT;
	if (params.offset < -push_swap->size_a * OFFSET_SIZE_RATE_LIMIT / 100)
		params.offset = -push_swap->size_a * OFFSET_SIZE_RATE_LIMIT / 100;
	offset_limit = OFFSET_UPPER_LIMIT;
	if (offset_limit > push_swap->size_a * OFFSET_SIZE_RATE_LIMIT / 100)
		offset_limit = push_swap->size_a * OFFSET_SIZE_RATE_LIMIT / 100;
	set_sorter_params(&best_params, __INT_MAX__, __INT_MAX__, __INT_MAX__);
	while (params.offset < offset_limit)
	{
		params.rate = RATE_LOWER_LIMIT - 1;
		while (params.rate++ < RATE_UPPER_LIMIT)
			run_iteration(&params, &best_params);
		offset++;
	}
	replace_stack(original->stack_a, push_swap->stack_a);
	setup(push_swap, best_params.offset, best_params.rate, 1);
	natural_merge_sort(push_swap, 1);
}
