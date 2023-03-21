#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"
#include "helper.h"

int	move_stack_a_to_value(t_push_swap *push_swap, int value, int verbose)
{
	int	distance;
	int	operations;
	int	steps;

	distance = find_element(push_swap->stack_a, push_swap->size_a, value);
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
