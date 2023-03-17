#include "sorters.h"
#include "application/application.h"
#include "operations/operations.h"

void	bubble_sort(t_app *app, int verbose)
{
	int	not_sorted;
	int	index;

	not_sorted = 0;
	while (not_sorted == 0)
	{
		index = 0;
		while (index < app->size_a)
		{
			if (index < app->size_a - 1
				&& app->stack_a->value >= app->stack_a->next->value)
				swap_a(app, verbose);
			rotate_a(app, verbose);
			index++;
		}
		not_sorted = is_sorted(app);
	}
}
