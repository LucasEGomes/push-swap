#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

// Validators

int	is_digit(char value);
int	is_space_or_null_byte(char value);
int	validate_input(int argc, char **argv);

#endif
