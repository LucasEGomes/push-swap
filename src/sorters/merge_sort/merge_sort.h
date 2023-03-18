#ifndef MERGE_SORT_H
# define MERGE_SORT_H
# include "application/application.h"

int	get_distance(t_dl_list *node, int total, int value);
int	get_group_size(t_dl_list *head, int limit, int ascending, int from_top);
int	find_element(t_dl_list *node, int total, int value);
int	is_single_group(t_dl_list *node, int size);

int	insert_top_b_into_a(t_app *app, int verbose);
int	move_stack_a_to_zero(t_app *app, int verbose);

int	merge_groups_a_to_b(t_app *app, int verbose);
int	merge_groups_b_to_a(t_app *app, int verbose);

#endif
