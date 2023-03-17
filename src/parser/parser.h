#ifndef PARSER_H
# define PARSER_H

// Validators

int	is_digit(char value);
int	validate_input(int argc, char **argv);

// Parsers

t_dl_list	*parse_number(char *string);

#endif
