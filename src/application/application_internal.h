#ifndef APPLICATION_INTERNAL_H
# define APPLICATION_INTERNAL_H
# include "entities/push_swap/push_swap.h"
# include "entities/sorter_parameters/sorter_parameters.h"

void	optimize_sort_steps(t_push_swap *orig_and_copy, t_sorter_params range,
			t_sorter_params step);

#endif
