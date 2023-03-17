#include "application/application.h"
#include "doubly_linked_list/doubly_linked_list.h"
#include "parser/parser.h"
#include <stddef.h>
#include <stdio.h>

static int	create_resources(t_dl_list **stack_a, int argc, char **argv)
{
	if (stack_a == NULL || validate_input(argc, argv))
		return (1);
	*stack_a = parse_number(argv[1]);
	if (*stack_a == NULL)
		return (1);
	printf("%d\n", (*stack_a)->value);
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
	if (create_resources(&stack_a, argc, argv) != 0)
		return (1);
	if (start_application(stack_a) != 0)
		return (1);
	free_resources(stack_a);
	return (0);
}
