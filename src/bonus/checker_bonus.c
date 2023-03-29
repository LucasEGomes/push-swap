/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:55 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/26 16:50:14 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/application_bonus.h"
#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "parser/parser.h"
#include <unistd.h>

static int	create_resources(t_dl_list **stack_a, int argc, char **argv)
{
	int	index;

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

static int	throw_program_exception(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_dl_list	*stack_a;
	int			result;

	(void) argv;
	if (argc < 2)
		return (0);
	if (validate_input(argc, argv))
		return (throw_program_exception());
	stack_a = NULL;
	if (create_resources(&stack_a, argc, argv) != 0)
		return (throw_program_exception());
	result = run_application(stack_a);
	if (result < 0)
		return (throw_program_exception());
	if (result != 0)
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
	return (0);
}
