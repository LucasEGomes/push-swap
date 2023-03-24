#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "parser_internal.h"
#include <stddef.h>

static t_dl_list	*negative_number(t_dl_list *node, char *number)
{
	number++;
	if (!is_digit(*number))
		return (abort_parse(&node));
	while (is_digit(*number))
	{
		if (is_int_underflow(node->value, *number - '0'))
			return (abort_parse(&node));
		node->value = node->value * 10 - (*number - '0');
		number++;
	}
	if (!is_space_or_null_byte(*number))
		return (abort_parse(&node));
	return (node);
}

static t_dl_list	*positive_number(t_dl_list *node, char *number)
{
	while (is_digit(*number))
	{
		if (is_int_overflow(node->value, *number - '0'))
			return (abort_parse(&node));
		node->value = node->value * 10 + (*number - '0');
		number++;
	}
	if (!is_space_or_null_byte(*number))
		return (abort_parse(&node));
	return (node);
}

t_dl_list	*parse_number(char *number)
{
	t_dl_list	*node;

	node = new_node_dl_list(0);
	if (node == NULL)
		return (NULL);
	node->value = 0;
	if (*number == '-')
		return (negative_number(node, number));
	return (positive_number(node, number));
}
