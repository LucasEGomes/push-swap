#include "doubly_linked_list/doubly_linked_list.h"
#include <criterion/criterion.h>
#include <criterion/theories.h>
#include <stddef.h>

#define APPEND_NODE_NEXT_ERROR "The next pointer of the first node must be the second node."
#define APPEND_NODE_PREV_ERROR "The previous pointer of the second node must be the first node."
#define APPEND_NODE_RESULT_SUCCESS_ERROR "Return value must be success. Expected 0, got %d."

TheoryDataPoints(doubly_linked_list, append_node) =
{
	DataPoints(int, 42, 42),
	DataPoints(int, 24, 24)
};

Theory((int first_value, int second_value), doubly_linked_list, append_node)
{
	t_dl_list	first;
	t_dl_list	second;
	int			result;
	
	first = (t_dl_list) {.value=first_value};
	second = (t_dl_list) {.value=second_value};
	result = append_node_dl_list(&first, &second);
	cr_expect_eq(first.next, &second, APPEND_NODE_NEXT_ERROR);
	cr_expect_eq(second.prev, &first, APPEND_NODE_PREV_ERROR);
	cr_expect_eq(result, 0, APPEND_NODE_RESULT_SUCCESS_ERROR, result);
}
