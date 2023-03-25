/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_range_b_into_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:39:03 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:39:04 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/push_swap/push_swap.h"
#include "helper.h"

int	insert_range_b_into_a(t_push_swap *push_swap, int elements, int verbose)
{
	int	steps;

	steps = 0;
	while (elements-- > 0)
		steps += insert_top_b_into_a(push_swap, verbose);
	return (steps);
}
