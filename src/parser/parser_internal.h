/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:38:38 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:38:38 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H
# include "entities/doubly_linked_list/doubly_linked_list.h"

// Validators

int			is_digit(char value);
int			is_int_underflow(int current, int addend);
int			is_int_overflow(int current, int addend);
int			is_space_or_null_byte(char value);
int			is_valid_input(char value);

// Error handlers

t_dl_list	*abort_parse(t_dl_list **node);

// Sub parsers

t_dl_list	*parse_number(char *number);

#endif
