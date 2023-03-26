#include "reader_bonus.h"
#include <unistd.h>

enum e_operators {ERROR, PA, PB, RRA, RRB, RRR, RA, RB, RR, SA, SB, SS};

static int	parse_operation(char *operation)
{
	(void) operation;
	return (ERROR);
}

int	read_operation(void)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	index;
	ssize_t	read_bytes;
	int		operation_index;
	char	operation[5];

	operation[4] = '\0';
	operation_index = 0;
	while (buffer[index] != '\n')
	{
		while (operation_index < 4 && buffer[index] != '\n' && buffer[index] != '\0')
		{
			operation[operation_index] = buffer[index];
			operation_index++;
			index++;
		}
		if (buffer[index] == '\0')
		{
			read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (read_bytes < 0)
			{
				operation[operation_index] = '\0';
				return (__INT_MAX__);
			}
			buffer[read_bytes] = '\0';
			if (read_bytes < 1)
				return (__INT_MAX__);
			index = 0;
		}
		else if (operation_index < 4)
		{
			operation[operation_index] = buffer[index];
			operation[operation_index + 1] = '\0';
		}
		else
			index++;
	}
	index++;
	if (operation_index == 0)
		return (-1);
	return (parse_operation(operation));
}
