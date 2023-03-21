#include "few_elements_sort_internal.h"
#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"

int	sort_stack_3_elements(t_push_swap *push_swap, int is_stack_a, int verbose)
{
	if (push_swap->stack_a->value < push_swap->stack_a->next->value)
	{
		if (push_swap->stack_a->next->value < push_swap->stack_a->prev->value)
			return (0);
		if (push_swap->stack_a->value > push_swap->stack_a->prev->value)
			return (sort_1_2_0(push_swap, is_stack_a, verbose));
		return (sort_0_2_1(push_swap, is_stack_a, verbose));
	}
	if (push_swap->stack_a->value < push_swap->stack_a->prev->value)
		return (sort_1_0_2(push_swap, is_stack_a, verbose));
	if (push_swap->stack_a->next->value < push_swap->stack_a->prev->value)
		return (sort_2_0_1(push_swap, is_stack_a, verbose));
	return (sort_2_1_0(push_swap, is_stack_a, verbose));
}

int	sort_3_elements(t_push_swap *push_swap, int verbose)
{
	return (sort_stack_3_elements(push_swap, 1, verbose));
}
