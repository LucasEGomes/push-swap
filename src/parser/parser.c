#include "doubly_linked_list/doubly_linked_list.h"
#include "parser.h"
#include <stddef.h>

static t_dl_list	*abort_parse(t_dl_list *node)
{
	delete_node_dl_list(node);
	return (NULL);
}

t_dl_list	*parse_number(char *string)
{
	t_dl_list	*node;
	int			signal;

	node = new_node_dl_list(0);
	if (node == NULL)
		return (NULL);
	node->value = 0;
	signal = 1;
	if (*string == '-')
	{
		signal = -1;
		string++;
	}
	while (is_digit(*string))
	{
		node->value = node->value * 10 + (*string - '0');
		if (node->value < 0)
			return (abort_parse(node));
		string++;
	}
	if (*string != '\0' && *string != ' ')
		return (abort_parse(node));
	node->value *= signal;
	return (node);
}
