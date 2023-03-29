/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:36 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/27 15:11:25 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application_internal_bonus.h"
#include "bonus/operations/operations_bonus.h"
#include "bonus/reader/reader_bonus.h"
#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include "helper/helper.h"
#include "operations/operations.h"
#include "sorters/bubble_sort/bubble_sort.h"
#include <unistd.h>

static int	free_application_resources(t_push_swap *push_swap, int return_code)
{
	delete_list_dl_list(&(push_swap->stack_a));
	delete_list_dl_list(&(push_swap->stack_b));
	return (return_code);
}

static void	run_operations(t_push_swap *push_swap)
{
	const t_operator	operators[] = {
		&skip_operation,
		&error_operation,
		&push_a, &push_b,
		&reverse_rotate_a, &reverse_rotate_b, &reverse_rotate_both,
		&rotate_a, &rotate_b, &rotate_both,
		&swap_a, &swap_b, &swap_both
	};
	enum e_operators	operator;

	operator = 1;
	while (operator <= TOTAL_OPERATIONS)
	{
		operator = read_operation();
		if (operator >= 0 && operator <= TOTAL_OPERATIONS)
			operators[operator](push_swap, 0);
	}
}

static int	has_duplications_unsorted(t_dl_list *stack, int size)
{
	t_dl_list	*current;
	t_dl_list	*pivot;
	int			index;
	int			start;

	start = 0;
	current = stack;
	while (start < size - 1)
	{
		index = start + 1;
		pivot = current->next;
		while (index < size)
		{
			if (current->value == pivot->value)
				return (1);
			index++;
			pivot = pivot->next;
		}
		current = current->next;
		start++;
	}
	return (0);
}

int	run_application(t_dl_list *stack_a)
{
	t_push_swap	push_swap;
	t_push_swap	*pointer;

	pointer = &push_swap;
	initialize_push_swap(pointer, stack_a);
	if (has_duplications_unsorted(pointer->stack_a, pointer->size_a))
		return (free_application_resources(pointer, -1));
	run_operations(pointer);
	if (!is_sorted(pointer))
		return (1);
	return (free_application_resources(pointer, 0));
}
