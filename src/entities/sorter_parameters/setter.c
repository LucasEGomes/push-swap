/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:39:19 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:39:19 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter_parameters.h"

void	set_sorter_params(t_sorter_params *params, int offset, int rate,
	int steps)
{
	*params = (t_sorter_parameters){
		.offset = offset,
		.rate = rate,
		.steps = steps
	};
}

void	copy_sorter_params(t_sorter_params *source, t_sorter_params *destiny)
{
	set_sorter_params(destiny, source->offset, source->rate, source->steps);
}
