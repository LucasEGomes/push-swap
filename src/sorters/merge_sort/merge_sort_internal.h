#ifndef MERGE_SORT_INTERNAL_H
# define MERGE_SORT_INTERNAL_H
# include "entities/doubly_linked_list/doubly_linked_list.h"
# include "entities/push_swap/push_swap.h"

int	get_group_size(t_dl_list *head, int limit, int ascending, int from_top);
int	is_single_group(t_dl_list *node, int size);

int	merge_groups_a_to_b(t_push_swap *push_swap, int verbose);
int	merge_groups_b_to_a(t_push_swap *push_swap, int verbose);

#endif
