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

// Properties

int			length_dl_list(t_dl_list *head);

// Handlers

int			connect_nodes_dl_list(t_dl_list *left, t_dl_list *right);
int			transform_into_circular_dl_list(t_dl_list *head);

// Destructors

void		delete_list_dl_list(t_dl_list **head);
void		delete_node_dl_list(t_dl_list *node);

#endif
