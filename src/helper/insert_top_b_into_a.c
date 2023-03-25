/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_top_b_into_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:39:02 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:39:02 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "helper.h"
#include "operations/operations.h"

int	insert_top_b_into_a(t_push_swap *push_swap, int verbose)
{
	int	distance;
	int	operations;
	int	steps;

	distance = get_distance(push_swap->stack_a, push_swap->size_a,
			push_swap->stack_b->value);
	steps = -distance * (distance < 0) + distance * (distance > 0);
	operations = steps + 1;
	if (distance > 0)
		while (steps-- > 0)
			rotate_a(push_swap, verbose);
	else
		while (steps-- > 0)
			reverse_rotate_a(push_swap, verbose);
	push_a(push_swap, verbose);
	return (operations);
}
