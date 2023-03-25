/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:38:44 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:38:45 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/doubly_linked_list/doubly_linked_list.h"
#include <stddef.h>

t_dl_list	*abort_parse(t_dl_list **node)
{
	delete_list_dl_list(node);
	return (NULL);
}
