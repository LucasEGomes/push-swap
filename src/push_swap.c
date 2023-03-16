#include "application/application.h"
#include "doubly_linked_list/doubly_linked_list.h"
#include <stddef.h>

static int	create_resources(t_dl_list **stack_a)
{
	if (stack_a == NULL)
		return (1);
	*stack_a = new_node_dl_list(42);
	if (*stack_a == NULL)
		return (1);
	return (0);
}

static void	free_resources(t_dl_list *stack_a)
{
	delete_list_dl_list(&stack_a);
}

int	main(int argc, char **argv)
{
	t_dl_list	*stack_a;

	(void) argv;
	if (argc < 2)
		return (0);
	if (create_resources(&stack_a) != 0)
		return (1);
	if (start_application(stack_a) != 0)
		return (1);
	free_resources(stack_a);
	return (0);
}
