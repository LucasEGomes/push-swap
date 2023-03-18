#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "entities/push_swap/push_swap.h"

// Swap

int	swap_a(t_push_swap *push_swap, int verbose);
int	swap_b(t_push_swap *push_swap, int verbose);
int	swap_both(t_push_swap *push_swap, int verbose);

// Push

int	push_a(t_push_swap *push_swap, int verbose);
int	push_b(t_push_swap *push_swap, int verbose);

// Rotate

int	rotate_a(t_push_swap *push_swap, int verbose);
int	rotate_b(t_push_swap *push_swap, int verbose);
int	rotate_both(t_push_swap *push_swap, int verbose);

// Reverse rotate

int	reverse_rotate_a(t_push_swap *push_swap, int verbose);
int	reverse_rotate_b(t_push_swap *push_swap, int verbose);
int	reverse_rotate_both(t_push_swap *push_swap, int verbose);

#endif
