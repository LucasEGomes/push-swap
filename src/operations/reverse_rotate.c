#include "application/application.h"
#include <unistd.h>

static void	reverse_rotate(t_dl_list **head)
{
	*head = (*head)->prev;
}

void	reverse_rotate_a(t_app *app, int verbose)
{
	if (app->size_a > 0)
		reverse_rotate(&(app->stack_a));
	if (verbose)
		write(STDOUT_FILENO, "rra", 3);
}

void	reverse_rotate_b(t_app *app, int verbose)
{
	if (app->size_b > 0)
		reverse_rotate(&(app->stack_b));
	if (verbose)
		write(STDOUT_FILENO, "rrb", 3);
}

void	reverse_rotate_both(t_app *app, int verbose)
{
	reverse_rotate_a(app, 0);
	reverse_rotate_b(app, 0);
	if (verbose)
		write(STDOUT_FILENO, "rrr", 3);
}
