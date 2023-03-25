/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_parameters.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:39:15 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:39:16 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_PARAMETERS_H
# define SORTER_PARAMETERS_H

typedef struct s_sorter_parameters
{
	int	offset;
	int	rate;
	int	steps;
}	t_sorter_parameters;
typedef struct s_sorter_parameters	t_sorter_params;

void	copy_sorter_params(t_sorter_params *source, t_sorter_params *destiny);
void	set_sorter_params(t_sorter_params *params, int offset, int rate,
			int steps);

#endif
