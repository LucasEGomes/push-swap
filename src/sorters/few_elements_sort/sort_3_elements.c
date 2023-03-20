#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"

static int	sort_0_2_1(t_push_swap *push_swap, int verbose)
{
	swap_a(push_swap, verbose);
	rotate_a(push_swap, verbose);
	return (2);
}

static int	sort_1_0_2(t_push_swap *push_swap, int verbose)
{
	swap_a(push_swap, verbose);
	return (1);
}

static int	sort_1_2_0(t_push_swap *push_swap, int verbose)
{
	reverse_rotate_a(push_swap, verbose);
	return (1);
}

static int	sort_2_0_1(t_push_swap *push_swap, int verbose)
{
	rotate_a(push_swap, verbose);
	return (1);
}

int	sort_3_elements(t_push_swap *push_swap, int verbose)
{
	if (push_swap->stack_a->value < push_swap->stack_a->next->value)
	{
		if (push_swap->stack_a->next->value < push_swap->stack_a->prev->value)
			return (0);
		if (push_swap->stack_a->value > push_swap->stack_a->prev->value)
			return (sort_1_2_0(push_swap, verbose));
		return (sort_0_2_1(push_swap, verbose));
	}
	if (push_swap->stack_a->value < push_swap->stack_a->prev->value)
		return (sort_1_0_2(push_swap, verbose));
	if (push_swap->stack_a->next->value < push_swap->stack_a->prev->value)
		return (sort_2_0_1(push_swap, verbose));
	swap_a(push_swap, verbose);
	reverse_rotate_a(push_swap, verbose);
	return (2);
}
