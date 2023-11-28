/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:26:02 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/28 01:27:55 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo3(t_stack **stack_a)
{
	t_stack	*cursor;

	cursor = *stack_a;
	if (cursor->rank == 2 && cursor->next->rank == 3) // 2,3,1
		rra(stack_a);
	else if (cursor->rank == 3 && cursor->next->rank == 1) // 3,1,2
		ra(stack_a);
	else if (cursor->rank == 3 && cursor->next->rank == 2) // 3,2,1
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (cursor->rank == 2 && cursor->next->rank == 1) // 2,1,3
		sa(stack_a);
	else if (cursor->rank == 1 && cursor->next->rank == 3) // 1,3,2
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	algominus10(t_stack **stack_a, t_stack **stack_b)
{
	size_t	i;
	size_t len;
	t_stack	*cursor;

	i = 1;
	cursor = *stack_a;
	len = get_stack_len(stack_a);
	while (i < len - 3)
	{
		if (cursor->rank == i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	algo3(stack_a);
	cursor = *stack_b;
	while (cursor)
	{
		pa(stack_a, stack_b);
	}
}

void	phase_1(t_stack **stack_a, t_stack **stack_b)
{
	int		len;
	t_stack	*cursor;

	len = get_stack_len(stack_a);
	cursor = *stack_a;
	if (len == 3)
	{
		algo3(stack_a);
	}
	else if (len <= 10)
	{
		algominus10(stack_a, stack_b);
	}
}
