#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"
#include "sorters/bubble_sort/bubble_sort.h"
#include "sorters/few_elements_sort/few_elements_sort.h"
#include "sorters/merge_sort/merge_sort.h"
#include "helper/helper.h"
#include <stddef.h>
#include <stdio.h>

#define OFFSET_LOWER_LIMIT -50
#define OFFSET_UPPER_LIMIT 50
#define OFFSET_SIZE_RATE_LIMIT 50
#define RATE_LOWER_LIMIT 1
#define RATE_UPPER_LIMIT 99

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

void	optimize_sort_steps(t_push_swap *push_swap, t_push_swap *original)
{
	int	best_offset;
	int	offset;
	int	limit_offset;
	int	best_rate;
	int	rate;
	int	best_steps;
	int	steps;
	
	offset = OFFSET_LOWER_LIMIT;
	if (offset < -push_swap->size_a * OFFSET_SIZE_RATE_LIMIT / 100)
		offset = -push_swap->size_a * OFFSET_SIZE_RATE_LIMIT / 100;
	limit_offset = OFFSET_UPPER_LIMIT;
	if (limit_offset > push_swap->size_a * OFFSET_SIZE_RATE_LIMIT / 100)
		limit_offset = push_swap->size_a * OFFSET_SIZE_RATE_LIMIT / 100;
	best_offset = __INT_MAX__;
	best_rate = __INT_MAX__;
	best_steps = __INT_MAX__;
	while (offset < limit_offset)
	{
		rate = RATE_LOWER_LIMIT;
		while (rate < RATE_UPPER_LIMIT)
		{
			replace_stack(original->stack_a, push_swap->stack_a);
			steps = setup(push_swap, offset, rate, 0);
			steps += natural_merge_sort(push_swap, 0);
			if (steps < best_steps)
			{
				best_offset = offset;
				best_rate = rate;
				best_steps = steps;
			}
			rate++;
		}
		offset++;
	}
	replace_stack(original->stack_a, push_swap->stack_a);
	setup(push_swap, best_offset, best_rate, 1);
	natural_merge_sort(push_swap, 1);
}