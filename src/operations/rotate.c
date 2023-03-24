#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include <stddef.h>

static void	rotate(t_dl_list **head)
{
	*head = (*head)->next;
}

int	rotate_a(t_push_swap *push_swap, int verbose)
{
	if (push_swap->size_a > 0)
		rotate(&(push_swap->stack_a));
	if (verbose)
		write(STDOUT_FILENO, "ra\n", 3);
	return (1);
}

int	rotate_b(t_push_swap *push_swap, int verbose)
{
	if (push_swap->size_b > 0)
		rotate(&(push_swap->stack_b));
	if (verbose)
		write(STDOUT_FILENO, "rb\n", 3);
	return (1);
}

int	rotate_both(t_push_swap *push_swap, int verbose)
{
	rotate_a(push_swap, 0);
	rotate_b(push_swap, 0);
	if (verbose)
		write(STDOUT_FILENO, "rr\n", 3);
	return (1);
}
