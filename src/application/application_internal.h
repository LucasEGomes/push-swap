/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:37:16 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:37:17 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLICATION_INTERNAL_H
# define APPLICATION_INTERNAL_H
# include "entities/push_swap/push_swap.h"
# include "entities/sorter_parameters/sorter_parameters.h"

void	optimize_sort_steps(t_push_swap *orig_and_copy, t_sorter_params range,
			t_sorter_params step);

#endif
