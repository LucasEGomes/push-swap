#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "entities/doubly_linked_list/doubly_linked_list.h"

typedef struct s_push_swap
{
	t_dl_list	*stack_a;
	t_dl_list	*stack_b;
	int			size_a;
	int			size_b;
}	t_push_swap;

// Setters

int		copy_push_swap(t_push_swap *source, t_push_swap *destiny);
void	initialize_push_swap(t_push_swap *push_swap, t_dl_list *stack_a);
void	replace_with_index_push_swap(t_push_swap *source, t_push_swap *destiny);

#endif
