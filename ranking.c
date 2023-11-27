/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:51:27 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/27 17:12:16 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static min_value(t_stack **stack, int rank)
{
	t_stack *cursor;
	t_stack *tmp;

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
	len = 1;
	while (cursor->next != *stack)
	{
		len++;
		cursor = cursor->next;
	}
	i = 0;
	while (i <= len)
		min_value(stack, i++);
}
