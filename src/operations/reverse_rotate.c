#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include <stddef.h>

static void	reverse_rotate(t_dl_list **head)
{
	*head = (*head)->prev;
}

int	reverse_rotate_a(t_push_swap *push_swap, int verbose)
{
	if (push_swap->size_a > 0)
		reverse_rotate(&(push_swap->stack_a));
	if (verbose)
		write(STDOUT_FILENO, "rra\n", 4);
	return (1);
}

int	reverse_rotate_b(t_push_swap *push_swap, int verbose)
{
	if (push_swap->size_b > 0)
		reverse_rotate(&(push_swap->stack_b));
	if (verbose)
		write(STDOUT_FILENO, "rrb\n", 4);
	return (1);
}

int	reverse_rotate_both(t_push_swap *push_swap, int verbose)
{
	reverse_rotate_a(push_swap, 0);
	reverse_rotate_b(push_swap, 0);
	if (verbose)
		write(STDOUT_FILENO, "rrr\n", 4);
	return (1);
}
