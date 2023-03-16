#include "doubly_linked_list.h"
#include <stdlib.h>

void	delete_node_dl_list(t_dl_list *node)
{
	node->value = 0;
	node->next = NULL;
	node->prev = NULL;
	free(node);
}

void	delete_list_dl_list(t_dl_list **head)
{
	t_dl_list	*first;
	t_dl_list	*node;
	t_dl_list	*next;

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
