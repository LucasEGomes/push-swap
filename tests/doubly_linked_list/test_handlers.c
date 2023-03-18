#include "entities/doubly_linked_list/doubly_linked_list.h"
#include <criterion/criterion.h>
#include <criterion/theories.h>
#include <stddef.h>

#define CONNECT_NODES_NEXT_ERROR "The next pointer of the first node must be the second node."
#define CONNECT_NODES_PREV_ERROR "The previous pointer of the second node must be the first node."
#define CONNECT_NODES_RESULT_ERROR "Return value must be %s. Expected %d, got %d."

TheoryDataPoints(doubly_linked_list, connect_nodes) =
{
	DataPoints(int, 42, 24),
	DataPoints(int, 24, 42)
};

Theory((int first_value, int second_value), doubly_linked_list, connect_nodes)
{
	t_dl_list	first;
	t_dl_list	second;
	int			result;
	
	first = (typeof(first)) {.value=first_value};
	second = (typeof(second)) {.value=second_value};
	result = connect_nodes_dl_list(&first, &second);
	cr_expect_eq(first.next, &second, CONNECT_NODES_NEXT_ERROR);
	cr_expect_eq(second.prev, &first, CONNECT_NODES_PREV_ERROR);
	cr_expect_eq(result, 0, CONNECT_NODES_RESULT_ERROR, "success", 0, result);
}

Test(doubly_linked_list, connect_nodes_fails)
{
	t_dl_list	node;
	int			result;

	node = (typeof(node)) {.value=42};
	result = connect_nodes_dl_list(NULL, &node);
	cr_expect_eq(result, 1, CONNECT_NODES_RESULT_ERROR, "failure", 1, result);
	cr_assert(node.value == 42 && node.next == NULL && node.prev == NULL);
	result = connect_nodes_dl_list(&node, NULL);
	cr_expect_eq(result, 1, CONNECT_NODES_RESULT_ERROR, "failure", 1, result);
	cr_assert(node.value == 42 && node.next == NULL && node.prev == NULL);
	result = connect_nodes_dl_list(NULL, NULL);
	cr_expect_eq(result, 1, CONNECT_NODES_RESULT_ERROR, "failure", 1, result);
}


TheoryDataPoints(doubly_linked_list, transform_into_circular) =
{
	DataPoints(int, 42, 24),
	DataPoints(int, 24, 42),
	DataPoints(int, 21, 12)
};

Theory((int a, int b, int c), doubly_linked_list, transform_into_circular)
{
	t_dl_list	first;
	t_dl_list	second;
	t_dl_list	third;
	int			result;
	
	first = (typeof(first)) {.value=a, .next=&second};
	second = (typeof(second)) {.value=b, .next=&third, .prev=&first};
	third = (typeof(third)) {.value=c, .prev=&second};
	result = transform_into_circular_dl_list(&first);
	cr_expect_eq(first.next, &second);
	cr_expect_eq(second.next, &third);
	cr_expect_eq(third.next, &first);
	cr_expect_eq(first.prev, &third);
	cr_expect_eq(second.prev, &first);
	cr_expect_eq(third.prev, &second);
	cr_expect_eq(third.prev, &second);
	cr_expect_eq(first.value, a);
	cr_expect_eq(second.value, b);
	cr_expect_eq(third.value, c);
	cr_expect_eq(result, 0);
}

Test(doubly_linked_list, transform_into_circular_single_element)
{
	t_dl_list	first;
	int			result;

	first = (typeof(first)) {.value=42};
	result = transform_into_circular_dl_list(&first);
	cr_expect_eq(first.next, &first);
	cr_expect_eq(first.prev, &first);
	cr_expect_eq(first.value, 42);
	cr_expect_eq(result, 0);
}

Test(doubly_linked_list, transform_into_circular_fails)
{
	t_dl_list	first;
	t_dl_list	second;
	int			result;

	result = transform_into_circular_dl_list(NULL);
	cr_expect_eq(result, 1);
	first = (typeof(first)) {.value=42, .next=&second, .prev=&second};
	second = (typeof(first)) {.value=24, .next=&first, .prev=&first};
	result = transform_into_circular_dl_list(&first);
	cr_assert(first.next == &second && first.prev == &second && first.value == 42);
	cr_assert(second.next == &first && second.prev == &first && second.value == 24);
	cr_expect_eq(result, 1);
}