#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"

int	split_stack_a(t_push_swap *push_swap, int size, int verbose)
{
	int	steps;

	steps = 0;
	while (size-- > 0 && push_swap->size_a > 0)
		steps += push_b(push_swap, verbose);
	return (steps);
}
