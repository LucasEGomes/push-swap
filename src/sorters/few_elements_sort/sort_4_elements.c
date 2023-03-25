/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:38:20 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:38:20 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/push_swap/push_swap.h"
#include "few_elements_sort_internal.h"
#include "helper/helper.h"
#include "operations/operations.h"

int	sort_4_elements(t_push_swap *push_swap, int verbose)
{
	int	steps;

	push_b(push_swap, verbose);
	steps = 1;
	steps += sort_stack_3_elements(push_swap, 1, verbose);
	steps += insert_top_b_into_a(push_swap, verbose);
	steps += move_stack_a_to_value(push_swap, 0, verbose);
	return (steps);
}
