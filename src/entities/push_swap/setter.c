#include "entities/push_swap/push_swap.h"
#include "entities/doubly_linked_list/doubly_linked_list.h"
#include <stddef.h>

void	initialize_push_swap(t_push_swap *push_swap, t_dl_list *stack_a)
{
	push_swap->stack_a = stack_a;
	push_swap->size_a = length_dl_list(stack_a);
	push_swap->stack_b = NULL;
	push_swap->size_b = 0;
}
