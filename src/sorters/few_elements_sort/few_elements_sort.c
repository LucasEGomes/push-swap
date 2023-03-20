#include "entities/push_swap/push_swap.h"
#include "few_elements_sort_internal.h"

int	few_elements_sort(t_push_swap *push_swap, int verbose)
{
	const t_sorter	sorters[9] = {
		sort_2_elements,
		sort_3_elements,
		sort_4_elements,
		sort_5_elements,
		sort_6_elements,
		sort_7_elements,
		sort_8_elements,
		sort_9_elements,
		sort_10_elements
	};

	return (sorters[push_swap->size_a - 2](push_swap, verbose));
}
