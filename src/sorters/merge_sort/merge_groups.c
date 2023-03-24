#include "operations/operations.h"
#include "merge_sort_internal.h"

static int	can_push_a(t_push_swap *push_swap)
{
	return (push_swap->stack_b->value > push_swap->stack_a->prev->value);
}

static int	can_push_b(t_push_swap *push_swap)
{
	return (push_swap->stack_a->value < push_swap->stack_b->prev->value);
}

int	merge_groups_a_to_b(t_push_swap *push_swap, int verbose)
{
	int	steps;
	int	steps_a;
	int	steps_b;

	steps_a = get_group_size(push_swap->stack_a, push_swap->size_a, 1, 1);
	steps_b = get_group_size(push_swap->stack_b, push_swap->size_b, 0, 0);
	steps = steps_a + steps_b;
	while (steps_a > 0 || steps_b > 0)
	{
		if (steps_b > 0 && (steps_a <= 0 || !can_push_b(push_swap)))
		{
			steps_b--;
			reverse_rotate_b(push_swap, verbose);
		}
		else
		{
			steps_a--;
			push_b(push_swap, verbose);
		}
	}
	return (steps);
}

int	merge_groups_b_to_a(t_push_swap *push_swap, int verbose)
{
	int	steps;
	int	steps_a;
	int	steps_b;

	steps_a = get_group_size(push_swap->stack_a, push_swap->size_a, 1, 0);
	steps_b = get_group_size(push_swap->stack_b, push_swap->size_b, 0, 1);
	steps = steps_a + steps_b;
	while (steps_a > 0 || steps_b > 0)
	{
		if (steps_a > 0 && (steps_b <= 0 || !can_push_a(push_swap)))
		{
			steps_a--;
			reverse_rotate_a(push_swap, verbose);
		}
		else
		{
			steps_b--;
			push_a(push_swap, verbose);
		}
	}
	return (steps);
}
