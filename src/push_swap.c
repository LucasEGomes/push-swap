#include "application/application.h"
#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "parser/parser.h"
#include <stddef.h>

static int	create_resources(t_dl_list **stack_a, int argc, char **argv)
{
	int	index;
	if (validate_input(argc, argv))
		return (1);
	index = 1;
	while (index < argc)
	{
		*stack_a = parse_string(*stack_a, argv[index]);
		index++;
	}
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
	stack_a = NULL;
	if (create_resources(&stack_a, argc, argv) != 0)
		return (1);
	if (start_application(stack_a) != 0)
	{
		free_resources(stack_a);
		return (1);
	}
	free_resources(stack_a);
	return (0);
}
