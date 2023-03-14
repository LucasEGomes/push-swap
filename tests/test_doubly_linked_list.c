#include "doubly_linked_list/doubly_linked_list.h"
#include <criterion/criterion.h>
#include <criterion/theories.h>
#include <stdio.h>

#define NEW_NODE_VALUE_ERROR "Node value with wrong value."\
	" Expected %d, got %d."
#define NEW_NODE_NEXT_ERROR "Node next pointer must be NULL."
#define NEW_NODE_PREV_ERROR "Node previous pointer must be NULL."

TheoryDataPoints(doubly_linked_list, new_node) = {
	DataPoints(int, 42, 24)
};

Theory((int value), doubly_linked_list, new_node) {
	t_dl_list *node;

	node = new_node_dl_list(value);
	if (node == NULL)
		cr_skip("Failed to allocate dynamic memory.");
	cr_expect_eq(node->value, value, NEW_NODE_VALUE_ERROR , value, node->value);
	cr_expect_null(node->next, NEW_NODE_NEXT_ERROR);
	cr_expect_null(node->prev, NEW_NODE_PREV_ERROR);
	free(node);
}
