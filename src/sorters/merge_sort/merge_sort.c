#include "application/application.h"
#include "operations/operations.h"
#include "merge_sort.h"

static int	move_unmerged_b_to_top(t_app *app, int moves, int verbose)
{
	int	steps;

	if (moves == app->size_b || moves <= 0)
		return (0);
	steps = 0;
	steps += moves;
	while (moves-- > 0)
		reverse_rotate_b(app, verbose);
	return (steps);
}

static int	merge_stacks(t_app *app, int total, int verbose)
{
	int	steps;

	steps = 0;
	while (app->size_a > total / 4)
		steps += merge_groups_a_to_b(app, verbose);
	if (is_single_group(app->stack_a, app->size_a))
		return (steps);
	steps += move_unmerged_b_to_top(app, app->size_b - steps, verbose);
	while (app->size_b > total / 2)
		steps += merge_groups_b_to_a(app, verbose);
	return (steps);
}

int	natural_merge_sort(t_app *app, int verbose)
{
	int	steps;
	int	size;

	size = app->size_a + app->size_b;
	steps = 0;
	while (!is_single_group(app->stack_a, app->size_a))
		steps += merge_stacks(app, size, verbose);
	while (app->size_b > 0)
		steps += insert_top_b_into_a(app, verbose);
	steps += move_stack_a_to_zero(app, verbose);
	return (steps);
}
