/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:38:55 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:38:56 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"

int	split_stack_a(t_push_swap *push_swap, int size, int verbose)
{
	int	steps;

	steps = 0;
	while (size-- > 0 && push_swap->size_a > 0)
		steps += push_b(push_swap, verbose);
	return (steps);
}
