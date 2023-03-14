#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

typedef struct s_doubly_linked_list	t_doubly_linked_list;
typedef struct s_doubly_linked_list
{
	t_doubly_linked_list	*prev;
	t_doubly_linked_list	*next;
	int						value;
}	t_doubly_linked_list;
typedef t_doubly_linked_list t_dl_list;

// Factories
t_dl_list	*new_node_dl_list(int value);

// Handlers
int			append_node_dl_list(t_dl_list *node, t_dl_list *next);

#endif
