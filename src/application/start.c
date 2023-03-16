#include "application.h"

static int	initialize_app(t_app *app, t_dl_list *stack_a)
{
	app->stack_a = stack_a;
	app->size_a = length_dl_list(stack_a);
	app->stack_b = NULL;
	app->size_b = 0;
}

int	start_application(t_dl_list *stack_a)
{
	t_app	app;

	initialize_app(&app, stack_a);
	return (0);
}