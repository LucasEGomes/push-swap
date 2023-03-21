#ifndef FEW_ELEMENTS_SORT_INTERNAL_H
# define FEW_ELEMENTS_SORT_INTERNAL_H
# include "entities/push_swap/push_swap.h"

typedef int (*t_sorter)(t_push_swap *push_swap, int verbose);

// Patterns of 3 elements

int	sort_0_2_1(t_push_swap *push_swap, int is_stack_a, int verbose);
int	sort_1_0_2(t_push_swap *push_swap, int is_stack_a, int verbose);
int	sort_1_2_0(t_push_swap *push_swap, int is_stack_a, int verbose);
int	sort_2_0_1(t_push_swap *push_swap, int is_stack_a, int verbose);
int	sort_2_1_0(t_push_swap *push_swap, int is_stack_a, int verbose);

// Generic sorter

int	sort_stack_3_elements(t_push_swap *push_swap, int is_stack_a, int verbose);

// Sorters

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
