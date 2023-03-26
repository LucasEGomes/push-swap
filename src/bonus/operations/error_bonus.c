/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:46 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/26 16:34:47 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/push_swap/push_swap.h"
#include <unistd.h>

int	error_operation(t_push_swap *push_swap, int verbose)
{
	(void) push_swap;
	(void) verbose;
	write(STDERR_FILENO, "Error\n", 6);
	return (0);
}
