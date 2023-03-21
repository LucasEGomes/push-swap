#include "few_elements_sort_internal.h"
#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"
#include "helper/helper.h"

int	sort_5_elements(t_push_swap *push_swap, int verbose)
{
	int	steps;

	steps = split_stack_a(push_swap, 2, verbose);
	steps += sort_stack_3_elements(push_swap, 1, verbose);
	steps += insert_range_b_into_a(push_swap, 2, verbose);
	steps += move_stack_a_to_value(push_swap, 0, verbose);
	return (steps);
}
