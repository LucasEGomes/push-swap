#ifndef PARSER_H
# define PARSER_H
# include "entities/doubly_linked_list/doubly_linked_list.h"

t_dl_list	*parse_string(t_dl_list *head, char *string);
int			validate_input(int argc, char **argv);

#endif
