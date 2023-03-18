#include "merge_sort_internal.h"
#include "operations/operations.h"

int	insert_top_b_into_a(t_push_swap *push_swap, int verbose)
{
	int	distance;
	int	operations;
	int	steps;

	distance = get_distance(push_swap->stack_a, push_swap->size_a,
			push_swap->stack_b->value);
	steps = -distance * (distance < 0) + distance * (distance > 0);
	operations = steps + 1;
	if (distance > 0)
		while (steps-- > 0)
			rotate_a(push_swap, verbose);
	else
		while (steps-- > 0)
			reverse_rotate_a(push_swap, verbose);
	push_a(push_swap, verbose);
	return (operations);
}

int	move_stack_a_to_zero(t_push_swap *push_swap, int verbose)
{
	int	distance;
	int	operations;
	int	steps;

	distance = find_element(push_swap->stack_a, push_swap->size_a, 0);
	steps = -distance * (distance < 0) + distance * (distance > 0);
	operations = steps;
	if (distance > 0)
		while (steps-- > 0)
			rotate_a(push_swap, verbose);
	else
		while (steps-- > 0)
			reverse_rotate_a(push_swap, verbose);
	return (operations);
}
