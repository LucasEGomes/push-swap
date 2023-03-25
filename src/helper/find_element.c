/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:39:17 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:39:17 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/doubly_linked_list/doubly_linked_list.h"

int	find_element(t_dl_list *head, int total, int value)
{
	t_dl_list	*node;
	int			index;

	index = 0;
	node = head;
	while (node->value != value)
	{
		node = node->next;
		index++;
	}
	if (index > total / 2)
		return (index - total);
	return (index);
}
