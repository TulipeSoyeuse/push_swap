/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:26:02 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/30 19:24:40 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr_or_r(t_stack **stack, size_t rank)
{
	t_stack	*cursor_f;
	t_stack	*cursor_b;
	int		rotate;

	cursor_f = *stack;
	cursor_b = *stack;
	rotate = 0;
	while (cursor_f->next != (*stack) && cursor_b->prev != *stack)
	{
		if (cursor_f->rank == rank)
			return (rotate);
		if (cursor_b->rank == rank)
			return (-rotate);
		rotate++;
		cursor_f = cursor_f->next;
		cursor_b = cursor_b->prev;
	}
	if (cursor_f->rank == rank)
		return (rotate);
	if (cursor_b->rank == rank)
		return (-rotate);
	rotate++;
	cursor_f = cursor_f->next;
	cursor_b = cursor_b->prev;
	return (0);
}

void	algo3(t_stack **stack_a)
{
	t_stack	*cursor;

	cursor = *stack_a;
	if (cursor->rank < cursor->next->rank
		&& cursor->rank > cursor->next->next->rank) // 2, 3, 1
		rra(stack_a);
	else if (cursor->rank > cursor->next->next->rank
		&& cursor->next->next->rank > cursor->next->rank) // 3, 1 ,2
		ra(stack_a);
	else if (cursor->rank > cursor->next->rank
		&& cursor->next->rank > cursor->next->next->rank) // 3, 2, 1
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (cursor->next->next->rank > cursor->rank
		&& cursor->rank > cursor->next->rank) // 2,1,3
		sa(stack_a);
	else if (cursor->next->next->rank > cursor->rank
		&& cursor->next->rank > cursor->rank) // 1,3,2
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	algominus10(t_stack **stack_a, t_stack **stack_b)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = get_stack_len(stack_a);
	while (++i < len - 2)
		phase_2_rotate(stack_a, stack_b, i);	
	if ((*stack_a)->rank > (*stack_a)->next->rank > (*stack_a)->next->next->rank)
		return ;
	algo3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = get_stack_len(stack_a);
	if (len == 3)
	{
		if ((*stack_a)->rank > (*stack_a)->next->rank > (*stack_a)->next->next->rank)
			return ;
		algo3(stack_a);
	}
	else if (len == 2)
		sa(stack_a);
	else if (len <= 10)
		algominus10(stack_a, stack_b);
	else
		TURBOTRON_3000(stack_a, stack_b);
}
