/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:39:21 by luceduar          #+#    #+#             */
/*   Updated: 2023/03/25 11:39:21 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/doubly_linked_list/doubly_linked_list.h"
#include "entities/push_swap/push_swap.h"
#include <stddef.h>

void	initialize_push_swap(t_push_swap *push_swap, t_dl_list *stack_a)
{
	push_swap->stack_a = stack_a;
	push_swap->size_a = length_dl_list(stack_a);
	push_swap->stack_b = NULL;
	push_swap->size_b = 0;
}

int	copy_push_swap(t_push_swap *source, t_push_swap *destiny)
{
	destiny->size_a = source->size_a;
	destiny->size_b = source->size_b;
	if (source->stack_a != NULL)
	{
		destiny->stack_a = copy_dl_list(source->stack_a);
		if (destiny->stack_a == NULL)
			return (1);
	}
	else
		destiny->stack_a = NULL;
	if (source->stack_b == NULL)
	{
		destiny->stack_b = NULL;
		return (0);
	}
	destiny->stack_b = copy_dl_list(source->stack_b);
	if (destiny->stack_b == NULL)
	{
		delete_list_dl_list(&(destiny->stack_a));
		return (1);
	}
	return (0);
}

void	replace_with_index_push_swap(t_push_swap *source, t_push_swap *destiny)
{
	t_dl_list	*head;
	int			index;
	int			replaced;

	head = source->stack_a;
	index = 0;
	replaced = 0;
	while (replaced < source->size_a)
	{
		while (source->stack_a->value != destiny->stack_a->value)
		{
			source->stack_a = source->stack_a->next;
			index = (index + 1) % source->size_a;
		}
		destiny->stack_a->value = index;
		destiny->stack_a = destiny->stack_a->next;
		replaced++;
	}
	while (source->stack_a != head)
		source->stack_a = source->stack_a->next;
}
