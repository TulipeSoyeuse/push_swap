/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:21:07 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/28 13:56:06 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **stack_b)
{
	t_stack	*a;

	a = popleft(stack_b);
	append(stack_b, a);
	write(1, "rb\n", 3);
}

void	rra(t_stack **stack_a)
{
	t_stack	*a;

	a = pop(stack_a);
	appendleft(stack_a, a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*a;

	a = pop(stack_b);
	appendleft(stack_b, a);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;

	a = pop(stack_a);
	appendleft(stack_a, a);
	a = pop(stack_b);
	appendleft(stack_b, a);
	write(1, "rrr\n", 4);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;

	a = popleft(stack_b);
	append(stack_b, a);
	a = popleft(stack_a);
	append(stack_a, a);
	write(1, "rr\n", 3);
}
