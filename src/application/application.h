#ifndef APPLICATION_H
# define APPLICATION_H
# include "entities/doubly_linked_list/doubly_linked_list.h"

typedef struct s_app
{
	t_dl_list	*stack_a;
	t_dl_list	*stack_b;
	int			size_a;
	int			size_b;
}	t_app;

int	run_application(t_dl_list *stack_a);

#endif
