/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:51:27 by rdupeux           #+#    #+#             */
/*   Updated: 2023/12/27 14:12:01 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_value(t_stack **stack, int rank)
{
	t_stack	*cursor;
	t_stack	*tmp;

	cursor = *stack;
	tmp = NULL;
	while (cursor->next != *stack)
	{
		if (!(cursor->rank) && !tmp)
			tmp = cursor;
		if (!(cursor->rank) && tmp)
		{
			if (cursor->value < tmp->value)
				tmp = cursor;
		}
		cursor = cursor->next;
	}
	if (!(cursor->rank) && !tmp)
		tmp = cursor;
	if (!(cursor->rank) && tmp)
	{
		if (cursor->value < tmp->value)
			tmp = cursor;
	}
	tmp->rank = rank;
}

void	ranksort_stk(t_stack **stack)
{
	int		i;
	int		len;
	t_stack	*cursor;

	cursor = *stack;
	len = get_stack_len(stack);
	i = 0;
	while (cursor->next != *stack)
	{
		cursor->rank = 0;
		cursor = cursor->next;
	}
	cursor->rank = 0;
	while (i <= len)
		min_value(stack, i++);
}
