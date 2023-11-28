/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:35:49 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/27 21:26:43 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	appendleft(t_stack **stack, t_stack *to_append)
{
	if (!(*stack))
	{
		to_append->next = to_append;
		to_append->prev = to_append;
		*stack = to_append;
		return ;
	}
	to_append->next = *stack;
	to_append->prev = (*stack)->prev;
	(*stack)->prev->next = to_append;
	(*stack)->prev = to_append;
	*stack = to_append;
}

void	append(t_stack **stack, t_stack *to_append)
{
	if (!(*stack))
	{
		to_append->next = to_append;
		to_append->prev = to_append;
		*stack = to_append;
		return ;
	}
	to_append->next = *stack;
	to_append->prev = (*stack)->prev;
	(*stack)->prev->next = to_append;
	(*stack)->prev = to_append;
}

t_stack	*popleft(t_stack **stack)
{
	t_stack	*to_pop;

	to_pop = *stack;
	if (to_pop->next == to_pop && to_pop->prev == to_pop)
	{
		*stack = NULL;
		return (to_pop);
	}
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next->prev = (*stack)->prev;
	*stack = (*stack)->next;
	to_pop->next = NULL;
	to_pop->prev = NULL;
	return (to_pop);
}

t_stack	*pop(t_stack **stack)
{
	t_stack	*to_pop;

	to_pop = (*stack)->prev;
	if (to_pop->next == to_pop && to_pop->prev == to_pop)
	{
		*stack = NULL;
		return (to_pop);
	}
	(*stack)->prev = to_pop->prev;
	to_pop->prev->next = *stack;
	to_pop->prev = NULL;
	to_pop->next = NULL;
	return (to_pop);
}
