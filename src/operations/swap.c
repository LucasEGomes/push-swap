#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include <unistd.h>

static void	swap(t_dl_list **head)
{
	t_dl_list	*temp;

	temp = *head;
	*head = temp->next;
	connect_nodes_dl_list(temp->prev, temp->next);
	connect_nodes_dl_list(temp, (*head)->next);
	connect_nodes_dl_list(*head, temp);
}

int	swap_a(t_push_swap *push_swap, int verbose)
{
	if (push_swap->size_a > 1)
		swap(&(push_swap->stack_a));
	if (verbose)
		write(STDOUT_FILENO, "sa\n", 3);
	return (1);
}

int	swap_b(t_push_swap *push_swap, int verbose)
{
	if (push_swap->size_b > 1)
		swap(&(push_swap->stack_b));
	if (verbose)
		write(STDOUT_FILENO, "sb\n", 3);
	return (1);
}

int	swap_both(t_push_swap *push_swap, int verbose)
{
	swap_a(push_swap, 0);
	swap_b(push_swap, 0);
	if (verbose)
		write(STDOUT_FILENO, "ss\n", 3);
	return (1);
}
