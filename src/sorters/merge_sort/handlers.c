#include "application/application.h"
#include "operations/operations.h"
#include "merge_sort.h"

int	insert_top_b_into_a(t_app *app, int verbose)
{
	int	distance;
	int	operations;
	int	steps;

	distance = get_distance(app->stack_a, app->size_a,
			app->stack_b->value);
	steps = -distance * (distance < 0) + distance * (distance > 0);
	operations = steps + 1;
	if (distance > 0)
		while (steps-- > 0)
			rotate_a(app, verbose);
	else
		while (steps-- > 0)
			reverse_rotate_a(app, verbose);
	push_a(app, verbose);
	return (operations);
}

int	move_stack_a_to_zero(t_app *app, int verbose)
{
	int	distance;
	int	operations;
	int	steps;

	distance = find_element(app->stack_a, app->size_a, 0);
	steps = -distance * (distance < 0) + distance * (distance > 0);
	operations = steps;
	if (distance > 0)
		while (steps-- > 0)
			rotate_a(app, verbose);
	else
		while (steps-- > 0)
			reverse_rotate_a(app, verbose);
	return (operations);
}
