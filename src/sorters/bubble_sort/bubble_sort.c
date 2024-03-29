/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:38:33 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:38:33 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/push_swap/push_swap.h"
#include "helper/helper.h"
#include "operations/operations.h"

int	bubble_sort(t_push_swap *push_swap, int verbose)
{
	int	index;
	int	not_sorted;
	int	steps;

	not_sorted = 0;
	steps = 0;
	while (not_sorted == 0)
	{
		index = 0;
		while (index < push_swap->size_a)
		{
			steps++;
			if (index < push_swap->size_a - 1
				&& push_swap->stack_a->value >= push_swap->stack_a->next->value)
			{
				steps++;
				swap_a(push_swap, verbose);
			}
			rotate_a(push_swap, verbose);
			index++;
		}
		not_sorted = is_sorted(push_swap);
	}
	return (steps);
}
