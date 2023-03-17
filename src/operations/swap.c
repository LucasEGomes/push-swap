#include "application/application.h"
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

void	swap_a(t_app *app, int verbose)
{
	if (app->size_a > 1)
		swap(&(app->stack_a));
	if (verbose)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	swap_b(t_app *app, int verbose)
{
	if (app->size_b > 1)
		swap(&(app->stack_b));
	if (verbose)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	swap_both(t_app *app, int verbose)
{
	swap_a(app, 0);
	swap_b(app, 0);
	if (verbose)
		write(STDOUT_FILENO, "ss\n", 3);
}
