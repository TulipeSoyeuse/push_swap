/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:50:02 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/30 20:15:42 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*b;

	if (!((*stack_a)->next->next != *stack_a && (*stack_a)->next != *stack_a))
		return ;
	a = popleft(stack_a);
	b = popleft(stack_a);
	appendleft(stack_a, a);
	appendleft(stack_a, b);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	if (!((*stack_b)->next->next != *stack_b && (*stack_b)->next != *stack_b))
		return ;
	a = popleft(stack_b);
	b = popleft(stack_b);
	appendleft(stack_b, a);
	appendleft(stack_b, b);
	write(1, "sb\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;

	if (!(*stack_b))
		return ;
	a = popleft(stack_b);
	appendleft(stack_a, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;

	if (!(*stack_a))
		return ;
	a = popleft(stack_a);
	appendleft(stack_b, a);
	write(1, "pb\n", 3);
}

void	ra(t_stack **stack_a)
{
	t_stack	*a;

	a = popleft(stack_a);
	append(stack_a, a);
	write(1, "ra\n", 3);
}
