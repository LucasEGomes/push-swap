#ifndef HELPER_H
# define HELPER_H
# include "entities/doubly_linked_list/doubly_linked_list.h"
# include "entities/push_swap/push_swap.h"

int	find_element(t_dl_list *head, int total, int value);
int	get_distance(t_dl_list *node, int total, int value);
int	has_duplications(t_dl_list *node);
int	insert_top_b_into_a(t_push_swap *push_swap, int verbose);
int	is_sorted(t_push_swap *push_swap);
int	move_stack_a_to_zero(t_push_swap *push_swap, int verbose);

#endif
