/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.C                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:19:59 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/30 20:44:05 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_split(t_stack *stack, float min, float max, int split)
{
	if (split == SPLIT_NB)
		max = get_stack_len(&stack);
	if (stack->rank > min && stack->rank <= max)
		stack->split = split;
}

int	split_value_left(t_stack **stack, unsigned int split_nb,
		unsigned int split_nb_2)
{
	t_stack	*cursor;

	cursor = *stack;
	if (!cursor)
		return (0);
	while (cursor->next != *stack)
	{
		if (cursor->split == split_nb || cursor->split == split_nb_2)
			return (1);
		cursor = cursor->next;
	}
	if (cursor->split == split_nb || cursor->split == split_nb_2)
		return (1);
	return (0);
}
