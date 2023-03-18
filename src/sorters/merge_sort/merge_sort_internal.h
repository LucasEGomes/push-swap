#ifndef MERGE_SORT_INTERNAL_H
# define MERGE_SORT_INTERNAL_H
# include "entities/doubly_linked_list/doubly_linked_list.h"
# include "entities/push_swap/push_swap.h"

int	get_distance(t_dl_list *node, int total, int value);
int	get_group_size(t_dl_list *head, int limit, int ascending, int from_top);
int	find_element(t_dl_list *node, int total, int value);
int	is_single_group(t_dl_list *node, int size);

int	insert_top_b_into_a(t_push_swap *push_swap, int verbose);
int	move_stack_a_to_zero(t_push_swap *push_swap, int verbose);

int	merge_groups_a_to_b(t_push_swap *push_swap, int verbose);
int	merge_groups_b_to_a(t_push_swap *push_swap, int verbose);

#endif
