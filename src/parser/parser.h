#ifndef PARSER_H
# define PARSER_H

// Validators

int	is_digit(char value);
int	is_space_or_null_byte(char value);
int	validate_input(int argc, char **argv);

// Parsers

t_dl_list	*parse_number(char *number);
t_dl_list	*parse_string(t_dl_list *head, char *string);

#endif
