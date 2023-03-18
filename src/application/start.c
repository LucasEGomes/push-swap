#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"
#include "sorters/bubble_sort/bubble_sort.h"
#include "sorters/merge_sort/merge_sort.h"
#include <stddef.h>

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
	int	steps;
	int	pushes;

	pushes = rate * push_swap->size_a / 100;
	steps = pushes;
	while (pushes-- > 0)
		push_b(push_swap, verbose);
	return (steps);
}

static void	setup(t_push_swap *push_swap, int offset, int rate, int verbose)
{
	apply_offset(push_swap, offset, verbose);
	apply_rate(push_swap, rate, verbose);
}

int	start_application(t_dl_list *stack_a)
{
	t_push_swap	push_swap;
	t_push_swap	sorted;

	initialize_push_swap(&push_swap, stack_a);
	if (copy_push_swap(&push_swap, &sorted))
		return (1);
	setup(&push_swap, 0, 50, 1);
	natural_merge_sort(&push_swap, 1);
	delete_list_dl_list(&(sorted.stack_a));
	return (0);
}
