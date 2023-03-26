/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:49 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/26 16:34:49 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_BONUS_H
# define READER_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif
# define TOTAL_OPERATIONS 13

enum	e_operators {
	SKIP,
	ERROR,
	PA,
	PB,
	RRA,
	RRB,
	RRR,
	RA,
	RB,
	RR,
	SA,
	SB,
	SS
};
typedef struct s_hash_operation
{
	enum e_operators	operator;
	int					hash;
}	t_hash_operator;

int	read_operation(void);

#endif
