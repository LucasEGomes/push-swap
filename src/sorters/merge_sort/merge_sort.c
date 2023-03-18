#include "merge_sort_internal.h"
#include "operations/operations.h"

static int	move_unmerged_b_to_top(t_push_swap *push_swap, int moves, int verbose)
{
	int	steps;

	if (moves == push_swap->size_b || moves <= 0)
		return (0);
	steps = 0;
	steps += moves;
	while (moves-- > 0)
		reverse_rotate_b(push_swap, verbose);
	return (steps);
}

static int	merge_stacks(t_push_swap *push_swap, int total, int verbose)
{
	int	steps;

	steps = 0;
	while (push_swap->size_a > total / 4)
		steps += merge_groups_a_to_b(push_swap, verbose);
	if (is_single_group(push_swap->stack_a, push_swap->size_a))
		return (steps);
	steps += move_unmerged_b_to_top(push_swap, push_swap->size_b - steps, verbose);
	while (push_swap->size_b > total / 2)
		steps += merge_groups_b_to_a(push_swap, verbose);
	return (steps);
}

int	natural_merge_sort(t_push_swap *push_swap, int verbose)
{
	int	steps;
	int	size;

	size = push_swap->size_a + push_swap->size_b;
	steps = 0;
	while (!is_single_group(push_swap->stack_a, push_swap->size_a))
		steps += merge_stacks(push_swap, size, verbose);
	while (push_swap->size_b > 0)
		steps += insert_top_b_into_a(push_swap, verbose);
	steps += move_stack_a_to_zero(push_swap, verbose);
	return (steps);
}
