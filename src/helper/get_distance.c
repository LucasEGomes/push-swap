/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:39:44 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:39:45 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/doubly_linked_list/doubly_linked_list.h"
#include <stddef.h>

int	get_distance(t_dl_list *node, int total, int value)
{
	int	index;

	if (node == NULL)
		return (0);
	if (node->next == node)
		return (0);
	index = 0;
	while ((value > node->value || value < node->prev->value)
		&& !(node->value < node->prev->value && value > node->prev->value)
		&& !(node->value < node->prev->value && value < node->value))
	{
		node = node->next;
		index++;
	}
	if (index > total / 2)
		return (index - total);
	return (index);
}
