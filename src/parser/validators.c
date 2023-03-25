/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:38:37 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:38:37 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_int_underflow(int current, int addend)
{
	const int	int_min = -__INT_MAX__ - 1;

	return (current < int_min / 10 || current * 10 < int_min + addend);
}

int	is_int_overflow(int current, int addend)
{
	return (current > __INT_MAX__ / 10 || current * 10 > __INT_MAX__ - addend);
}

int	is_digit(char value)
{
	return (value >= '0' && value <= '9');
}

int	is_space_or_null_byte(char value)
{
	return (value == ' ' || value == '\0');
}

int	is_valid_input(char value)
{
	return (is_digit(value) || value == ' ' || value == '-');
}
