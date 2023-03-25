/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_patterns_of_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:38:12 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:38:12 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/push_swap/push_swap.h"
#include "operations/operations.h"

int	sort_0_2_1(t_push_swap *push_swap, int is_stack_a, int verbose)
{
	if (is_stack_a)
	{
		swap_a(push_swap, verbose);
		rotate_a(push_swap, verbose);
		return (2);
	}
	swap_b(push_swap, verbose);
	rotate_b(push_swap, verbose);
	return (2);
}

int	sort_1_0_2(t_push_swap *push_swap, int is_stack_a, int verbose)
{
	if (is_stack_a)
	{
		swap_a(push_swap, verbose);
		return (1);
	}
	swap_b(push_swap, verbose);
	return (1);
}

int	sort_1_2_0(t_push_swap *push_swap, int is_stack_a, int verbose)
{
	if (is_stack_a)
	{
		reverse_rotate_a(push_swap, verbose);
		return (1);
	}
	reverse_rotate_b(push_swap, verbose);
	return (1);
}

int	sort_2_0_1(t_push_swap *push_swap, int is_stack_a, int verbose)
{
	if (is_stack_a)
	{
		rotate_a(push_swap, verbose);
		return (1);
	}
	rotate_b(push_swap, verbose);
	return (1);
}

int	sort_2_1_0(t_push_swap *push_swap, int is_stack_a, int verbose)
{
	if (is_stack_a)
	{
		swap_a(push_swap, verbose);
		reverse_rotate_a(push_swap, verbose);
		return (2);
	}
	swap_b(push_swap, verbose);
	reverse_rotate_b(push_swap, verbose);
	return (2);
}
