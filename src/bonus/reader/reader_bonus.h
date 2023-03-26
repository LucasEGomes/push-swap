#ifndef READER_BONUS_H
# define READER_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

enum	e_operators {
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
