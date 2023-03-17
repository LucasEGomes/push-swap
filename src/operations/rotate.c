#include "application/application.h"
#include <unistd.h>

static void	rotate(t_dl_list **head)
{
	*head = (*head)->next;
}

void	rotate_a(t_app *app, int verbose)
{
	if (app->size_a > 0)
		rotate(&(app->stack_a));
	if (verbose)
		write(STDOUT_FILENO, "ra", 2);
}

void	rotate_b(t_app *app, int verbose)
{
	if (app->size_b > 0)
		rotate(&(app->stack_b));
	if (verbose)
		write(STDOUT_FILENO, "rb", 2);
}

void	rotate_both(t_app *app, int verbose)
{
	rotate_a(app, 0);
	rotate_b(app, 0);
	if (verbose)
		write(STDOUT_FILENO, "rr", 2);
}
