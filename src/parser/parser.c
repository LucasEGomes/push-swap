#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "parser_internal.h"
#include <stddef.h>

static t_dl_list	*create_head(char *string)
{
	t_dl_list	*head;

	head = parse_number(string);
	connect_nodes_dl_list(head, head);
	return (head);
}

int	validate_input(int argc, char **argv)
{
	char	*string;
	int		index;

	index = 1;
	while (index < argc)
	{
		string = argv[index];
		while (is_valid_input(*string))
			string++;
		if (*string != '\0')
			return (1);
		index++;
	}
	return (0);
}

t_dl_list	*parse_string(t_dl_list *head, char *string)
{
	t_dl_list	*node;

	if (head == NULL)
	{
		head = create_head(string);
		while (!is_space_or_null_byte(*string))
			string++;
	}
	if (head == NULL)
		return (NULL);
	node = head->prev;
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
