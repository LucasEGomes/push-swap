#include "application/application.h"
#include <stddef.h>

int	is_sorted(t_app *app)
{
	t_dl_list	*node;
	int			index;

	if (app->stack_b != NULL)
		return (0);
	index = 1;
	node = app->stack_a;
	while (index < app->size_a)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		index++;
	}
	return (1);
}
