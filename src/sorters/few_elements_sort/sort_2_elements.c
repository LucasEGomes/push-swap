#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"

int	sort_2_elements(t_push_swap *push_swap, int verbose)
{
	if (push_swap->stack_a->value < push_swap->stack_a->next->value)
		return (0);
	swap_a(push_swap, verbose);
	return (1);
}
