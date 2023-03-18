#include "application/application.h"
#include "operations/operations.h"
#include "merge_sort.h"

static int	can_push_a(t_app *app)
{
	return (app->stack_b->value > app->stack_a->prev->value);
}

static int	can_push_b(t_app *app)
{
	return (app->stack_a->value < app->stack_b->prev->value);
}

int	merge_groups_a_to_b(t_app *app, int verbose)
{
	int	steps_a;
	int	steps_b;
	int	steps;

	steps_a = get_group_size(app->stack_a, app->size_a, 1, 1);
	steps_b = get_group_size(app->stack_b, app->size_b, 0, 0);
	steps = steps_a + steps_b;
	while (steps_a > 0 || steps_b > 0)
	{
		if (steps_b > 0 && (steps_a <= 0 || !can_push_b(app)))
		{
			steps_b--;
			reverse_rotate_b(app, verbose);
		}
		else
		{
			steps_a--;
			push_b(app, verbose);
		}
	}
	return (steps);
}

int	merge_groups_b_to_a(t_app *app, int verbose)
{
	int	steps_a;
	int	steps_b;
	int	steps;

	steps_a = get_group_size(app->stack_a, app->size_a, 1, 0);
	steps_b = get_group_size(app->stack_b, app->size_b, 0, 1);
	steps = steps_a + steps_b;
	while (steps_a > 0 || steps_b > 0)
	{
		if (steps_a > 0 && (steps_b <= 0 || !can_push_a(app)))
		{
			steps_a--;
			reverse_rotate_a(app, verbose);
		}
		else
		{
			steps_b--;
			push_a(app, verbose);
		}
	}
	return (steps);
}
