#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include "helper/helper.h"
#include "operations/operations.h"
#include "sorters/bubble_sort/bubble_sort.h"
#include <unistd.h>

static int	free_application_resources(t_push_swap *push_swap, int return_code)
{
	delete_list_dl_list(&(push_swap->stack_a));
	delete_list_dl_list(&(push_swap->stack_b));
	return (return_code);
}

typedef int (*operator)(t_push_swap *push_swap, int verbose);

static int read_operation(void)
{
	return (0);
}

static void	run_operations(t_push_swap *push_swap)
{
	operator	operators[11] = {
		push_a, push_b,
		reverse_rotate_a, reverse_rotate_b, reverse_rotate_both,
		rotate_a, rotate_b,rotate_both,
		swap_a, swap_b, swap_both
	};
	int			operation;

	operation = 1;
	while (operation >= 0 && operation <= 10)
	{
		operation = read_operation();
		if (operation >= 0 && operation <= 10)
			operators[operation](push_swap, 0);
	}
}

int	run_application(t_dl_list *stack_a)
{
	t_push_swap	orig_and_copy[2];
	t_push_swap	*copy;
	t_push_swap	*orig;

	orig = orig_and_copy + 0;
	copy = orig_and_copy + 1;
	initialize_push_swap(orig, stack_a);
	if (orig->size_a >= 2)
	{
		if (copy_push_swap(orig, copy))
			return (1);
		bubble_sort(copy, 0);
		if (has_duplications(copy->stack_a))
			return (free_application_resources(copy, 1));
	}
	free_application_resources(copy, 0);
	run_operations(orig);
	if (!is_sorted(orig))
		return (1);
	return (0);
}
