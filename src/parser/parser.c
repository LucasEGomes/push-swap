#include "doubly_linked_list/doubly_linked_list.h"
#include "parser.h"
#include <stddef.h>

static t_dl_list	*abort_parse(t_dl_list **node)
{
	delete_list_dl_list(node);
	return (NULL);
}

t_dl_list	*parse_number(char *number)
{
	t_dl_list	*node;
	int			signal;

	node = new_node_dl_list(0);
	if (node == NULL)
		return (NULL);
	node->value = 0;
	signal = 1;
	if (*number == '-')
	{
		signal = -1;
		number++;
	}
	while (is_digit(*number))
	{
		node->value = node->value * 10 + (*number - '0');
		if (node->value < 0)
			return (abort_parse(&node));
		number++;
	}
	if (!is_space_or_null_byte(*number))
		return (abort_parse(&node));
	node->value *= signal;
	return (node);
}

static t_dl_list	*create_head(char *string)
{
	t_dl_list	*head;

	head = parse_number(string);
	connect_nodes_dl_list(head, head);
	return (head);
}

t_dl_list	*parse_string(t_dl_list *head, char *string)
{
	t_dl_list	*node;

	if (head == NULL)
		head = create_head(string);
	if (head == NULL)
		return (NULL);
	node = head->prev;
	while (!is_space_or_null_byte(*string))
		string++;
	while (*string != '\0')
	{
		if (*string == ' ')
			string++;
		node->next = parse_number(string);
		if (node->next == NULL)
			return (abort_parse(&head));
		connect_nodes_dl_list(node, node->next);
		node = node->next;
		while (!is_space_or_null_byte(*string))
			string++;
	}
	connect_nodes_dl_list(node, head);
	return (head);
}
