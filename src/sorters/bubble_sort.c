#include "sorters.h"
#include "application/application.h"
#include "operations/operations.h"

int	bubble_sort(t_app *app, int verbose)
{
	int	not_sorted;
	int	index;
	int	steps;

	not_sorted = 0;
	steps = 0;
	while (not_sorted == 0)
	{
		index = 0;
		while (index < app->size_a)
		{
			steps++;
			if (index < app->size_a - 1
				&& app->stack_a->value >= app->stack_a->next->value)
			{
				steps++;
				swap_a(app, verbose);
			}
			rotate_a(app, verbose);
			index++;
		}
		not_sorted = is_sorted(app);
	}
	return (steps);
}
