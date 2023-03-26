#include "entities/push_swap/push_swap.h"
#include <unistd.h>

int	error_operation(t_push_swap *push_swap, int verbose)
{
	(void) push_swap;
	(void) verbose;
	write(STDERR_FILENO, "Error\n", 6);
	return (0);
}
