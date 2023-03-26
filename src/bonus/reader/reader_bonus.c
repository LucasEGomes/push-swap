#include "reader_bonus.h"
#include <unistd.h>

static int	hash_function(char *value)
{
	unsigned int result;

	result = 0;
	result += ((unsigned  int)(value[0])) << 24;
	result += ((unsigned  int)(value[1])) << 16;
	result += ((unsigned  int)(value[2])) << 8;
	result += ((unsigned  int)(value[3]));
	return ((int)result);
}

static int	parse_operation(char *operation)
{
	const t_hash_operation	hashes[] = {
		{.hash = 0x70610A00, .operation = PA},
		{.hash = 0x70620A00, .operation = PB},
		{.hash = 0x7272610A, .operation = RRA},
		{.hash = 0x7272620A, .operation = RRB},
		{.hash = 0x7272720A, .operation = RRR},
		{.hash = 0x72610A00, .operation = RA},
		{.hash = 0x72620A00, .operation = RB},
		{.hash = 0x72720A00, .operation = RR},
		{.hash = 0x73610A00, .operation = SA},
		{.hash = 0x73620A00, .operation = SB},
		{.hash = 0x73730A00, .operation = SS},
	};
	int						hash;
	int						index;

	hash = hash_function(operation);
	index = 0;
	while (index < 11 && hash != hashes[index].hash)
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
		else if (buffer[index] != '\n')
			index++;
	}
	index++;
	if (operation_index >= 4)
		return (ERROR);
	if (operation_index <= 0)
		return (-1);
	return (parse_operation(operation));
}
