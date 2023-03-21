#include "few_elements_sort_internal.h"
#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"
#include "helper/helper.h"

int	sort_6_elements(t_push_swap *push_swap, int verbose)
{
	int	steps;

	push_b(push_swap, verbose);
	push_b(push_swap, verbose);
	steps = 2;
	steps += sort_4_elements(push_swap, verbose);
	steps += insert_top_b_into_a(push_swap, verbose);
	steps += insert_top_b_into_a(push_swap, verbose);
	steps += move_stack_a_to_zero(push_swap, verbose);
	return (steps);
}
