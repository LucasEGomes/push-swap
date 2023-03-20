#ifndef FEW_ELEMENTS_SORT_INTERNAL_H
# define FEW_ELEMENTS_SORT_INTERNAL_H
# include "entities/push_swap/push_swap.h"

typedef int (*t_sorter)(t_push_swap *push_swap, int verbose);

int	sort_2_elements(t_push_swap *push_swap, int verbose);
int	sort_3_elements(t_push_swap *push_swap, int verbose);
int	sort_4_elements(t_push_swap *push_swap, int verbose);
int	sort_5_elements(t_push_swap *push_swap, int verbose);
int	sort_6_elements(t_push_swap *push_swap, int verbose);
int	sort_7_elements(t_push_swap *push_swap, int verbose);
int	sort_8_elements(t_push_swap *push_swap, int verbose);
int	sort_9_elements(t_push_swap *push_swap, int verbose);
int	sort_10_elements(t_push_swap *push_swap, int verbose);

#endif
