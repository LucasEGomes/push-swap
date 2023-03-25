/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_7_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:38:15 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:38:16 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/push_swap/push_swap.h"
#include "few_elements_sort_internal.h"
#include "helper/helper.h"
#include "operations/operations.h"

int	sort_7_elements(t_push_swap *push_swap, int verbose)
{
	int	steps;

	steps = move_stack_a_to_value(push_swap, 0, verbose);
	steps += rotate_a(push_swap, verbose);
	steps += split_stack_a(push_swap, 3, verbose);
	steps += sort_4_elements(push_swap, verbose);
	steps += sort_stack_3_elements(push_swap, 0, verbose);
	steps += insert_range_b_into_a(push_swap, 3, verbose);
	steps += move_stack_a_to_value(push_swap, 0, verbose);
	return (steps);
}
