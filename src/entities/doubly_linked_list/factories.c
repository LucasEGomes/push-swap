/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factories.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:39:28 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:39:29 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include <stdlib.h>

t_dl_list	*new_node_dl_list(int value)
{
	t_dl_list	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_dl_list	*copy_dl_list(t_dl_list *source)
{
	t_dl_list	*node;
	t_dl_list	*result;
	int			size;

	result = new_node_dl_list(source->value);
	if (result == NULL)
		return (NULL);
	node = result;
	size = length_dl_list(source);
	while (size > 1)
	{
		source = source->next;
		node->next = new_node_dl_list(source->value);
		if (node->next == NULL)
		{
			delete_list_dl_list(&(result));
			return (NULL);
		}
		connect_nodes_dl_list(node, node->next);
		node = node->next;
		size--;
	}
	connect_nodes_dl_list(node, result);
	return (result);
}
