/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:39:32 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:39:32 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include <stdlib.h>

void	delete_node_dl_list(t_dl_list *node)
{
	node->next = NULL;
	node->prev = NULL;
	node->value = 0;
	free(node);
}

void	delete_list_dl_list(t_dl_list **head)
{
	t_dl_list	*first;
	t_dl_list	*next;
	t_dl_list	*node;

	if (head == NULL || *head == NULL)
		return ;
	first = *head;
	node = *head;
	while (node->next != NULL && node->next != first)
	{
		next = node->next;
		delete_node_dl_list(node);
		node = next;
	}
	delete_node_dl_list(node);
	*head = NULL;
}
