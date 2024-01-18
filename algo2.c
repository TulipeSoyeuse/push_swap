/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:05:29 by rdupeux           #+#    #+#             */
/*   Updated: 2024/01/18 12:11:24 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack_a)
{
	t_stack	*cursor;

	cursor = (*stack_a)->next;
	while (cursor != *stack_a)
	{
		if (cursor->prev->value > cursor->value)
		{
			return (0);
		}
		cursor = cursor->next;
	}
	return (1);
}

void	phase_2_rotate(t_stack **stack_a, t_stack **stack_b, int rank)
{
	int	rotate;

	if (is_sorted(stack_a))
		return ;
	rotate = rr_or_r(stack_a, rank);
	if (rotate < 0)
	{
		while (rotate++)
			rra(stack_a);
		if (is_sorted(stack_a))
			return ;
		pb(stack_a, stack_b);
	}
	else if (rotate >= 0)
	{
		while (rotate--)
			ra(stack_a);
		if (is_sorted(stack_a))
			return ;
		pb(stack_a, stack_b);
	}
}
