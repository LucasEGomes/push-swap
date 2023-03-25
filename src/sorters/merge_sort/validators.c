/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:37:57 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:37:58 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "merge_sort_internal.h"

int	is_single_group(t_dl_list *node, int size)
{
	return (get_group_size(node, size, 1, 1) == size);
}
