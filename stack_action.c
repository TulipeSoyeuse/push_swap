/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:35:49 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/25 13:05:26 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	appendleft(t_stack **stack, int content)
{
	t_stack	*new;

	new = node_new(content);
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
}

int	popleft(t_stack **stack)
{
	t_stack	*to_del;
	int		value;

	to_del = *stack;
	*stack = to_del->next;
	value = to_del->value;
	free(to_del);
	return (value);
}

void	append(t_stack **stack, int content)
{
	t_stack	*cur;
	t_stack	*new;

	new = node_new(content);
	if (!new)
		return ;
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

int	pop(t_stack **stack)
{
	t_stack	*cur;
	int		val;

	cur = *stack;
	while (cur->next->next)
		cur = cur->next;
	val = cur->next->value;
	free(cur->next);
	cur->next = NULL;
	return (val);
}

t_stack	*init_stack(int ac, char **av)
{
	int	i;
	t_stack *stack;

	i = 0;
	stack = node_new(ft_atoi(av[i]));
	while (++i < ac)
 	 	append(&stack, ft_atoi(av[i]));
	return (stack);
}
