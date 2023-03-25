/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:38:53 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:38:54 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "entities/push_swap/push_swap.h"

// Swap

int	swap_a(t_push_swap *push_swap, int verbose);
int	swap_b(t_push_swap *push_swap, int verbose);
int	swap_both(t_push_swap *push_swap, int verbose);

// Push

int	push_a(t_push_swap *push_swap, int verbose);
int	push_b(t_push_swap *push_swap, int verbose);

// Rotate

int	rotate_a(t_push_swap *push_swap, int verbose);
int	rotate_b(t_push_swap *push_swap, int verbose);
int	rotate_both(t_push_swap *push_swap, int verbose);

// Reverse rotate

int	reverse_rotate_a(t_push_swap *push_swap, int verbose);
int	reverse_rotate_b(t_push_swap *push_swap, int verbose);
int	reverse_rotate_both(t_push_swap *push_swap, int verbose);

#endif
