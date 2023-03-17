#include "application/application.h"
#include <unistd.h>

static void	push(t_dl_list **source, t_dl_list **destiny)
{
	t_dl_list	*new_head;
	
	new_head = (*source)->next;
	if (new_head == *source)
		new_head = NULL;
	connect_nodes_dl_list((*source)->prev, (*source)->next);
	connect_nodes_dl_list((*destiny)->prev, *source);
	connect_nodes_dl_list(*source, *destiny);
	*source = new_head;
	*destiny = *source;
}

void	push_a(t_app *app, int verbose)
{
	if (app->size_b > 0)
		push(&(app->stack_b), &(app->stack_a));
	if (verbose)
		write(STDOUT_FILENO, "pa\n", 3);
}

void	push_b(t_app *app, int verbose)
{
	if (app->size_a > 0)
		push(&(app->stack_a), &(app->stack_b));
	if (verbose)
		write(STDOUT_FILENO, "pb\n", 3);
}
