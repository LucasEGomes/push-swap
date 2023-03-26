/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:51 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/26 16:34:52 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_bonus.h"
#include <unistd.h>

static int	hash_function(char *value)
{
	unsigned int	result;

	result = 0;
	result += ((unsigned int)(value[0])) << 24;
	result += ((unsigned int)(value[1])) << 16;
	result += ((unsigned int)(value[2])) << 8;
	result += ((unsigned int)(value[3]));
	return ((int)result);
}

static int	parse_operation(char *operation)
{
	const t_hash_operator	hashes[] = {
	{.hash = 0x70610A00, .operator = PA},
	{.hash = 0x70620A00, .operator = PB},
	{.hash = 0x7272610A, .operator = RRA},
	{.hash = 0x7272620A, .operator = RRB},
	{.hash = 0x7272720A, .operator = RRR},
	{.hash = 0x72610A00, .operator = RA},
	{.hash = 0x72620A00, .operator = RB},
	{.hash = 0x72720A00, .operator = RR},
	{.hash = 0x73610A00, .operator = SA},
	{.hash = 0x73620A00, .operator = SB},
	{.hash = 0x73730A00, .operator = SS},
	};
	int						hash;
	int						index;

	if (*operation == '\n')
		return (SKIP);
	hash = hash_function(operation);
	index = 0;
	while (index < 11 && hash != hashes[index].hash)
		index++;
	if (index >= 11)
		return (ERROR);
	return (hashes[index].operator);
}

static int	read_next_buffer(char *buffer)
{
	ssize_t	read_bytes;

	read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
		return (__INT_MAX__);
	buffer[read_bytes] = '\0';
	if (read_bytes < 1)
		return (__INT_MAX__);
	return (0);
}

int	read_operation(void)
{
	static int	index;
	int			op_index;
	static char	buffer[BUFFER_SIZE + 1];
	char		operation[5];

	operation[4] = '\0';
	op_index = 0;
	while (buffer[index] != '\n')
	{
		if (buffer[index] == '\0')
		{
			index = 0;
			if (read_next_buffer(buffer) > 0)
				return (__INT_MAX__);
		}
		while (op_index < 3 && buffer[index] != '\n' && buffer[index] != '\0')
			operation[op_index++] = buffer[index++];
		operation[op_index] = buffer[index];
		if (buffer[index] != '\n' && buffer[index] != '\0')
			index++;
	}
	operation[op_index + 1] = '\0';
	index++;
	return (parse_operation(operation));
}
