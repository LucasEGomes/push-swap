#include "doubly_linked_list/doubly_linked_list.h"
#include <criterion/criterion.h>
#include <criterion/theories.h>

TheoryDataPoints(doubly_linked_list, new_node) = {
	DataPoints(int, 42, 24)
};

Theory((int value), doubly_linked_list, new_node) {
	t_dl_list *node;

	node = new_node_dl_list(value);
	cr_assert_not_null(node);
	cr_expect_eq(node->value, value);
	cr_expect_null(node->next);
	cr_expect_null(node->prev);
}
