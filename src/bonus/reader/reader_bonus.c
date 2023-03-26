#include "reader_bonus.h"
#include <unistd.h>

static int	hash_function(char *value)
{
	int result;

	result = 0;
	result += ((int)(value[0])) << 16;
	result += ((int)(value[1])) << 8;
	result += ((int)(value[2]));
	return (result);
}

static int	parse_operation(char *operation)
{
	const t_hash_operation	hashes[] = {
		{.hash = 0x0070610A, .operation = PA},
		{.hash = 0x0070620A, .operation = PB},
		{.hash = 0x00727261, .operation = RRA},
		{.hash = 0x00727262, .operation = RRB},
		{.hash = 0x00727272, .operation = RRR},
		{.hash = 0x0072610A, .operation = RA},
		{.hash = 0x0072620A, .operation = RB},
		{.hash = 0x0072720A, .operation = RR},
		{.hash = 0x0073610A, .operation = SA},
		{.hash = 0x0073620A, .operation = SB},
		{.hash = 0x0073730A, .operation = SS},
	};
	int						hash;
	int						index;

	hash = hash_function(operation);
	index = 0;
	while (hash != hashes[index].hash && index < 11)
		index++;
	if (index >= 11)
		return (ERROR);
	return (hashes[index].operation);
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
