/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:21:58 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/30 20:50:39 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*node_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

t_stack	*init_stack(int ac, char **av)
{
	int		i;
	t_stack	*stack;
	t_stack	*tmp;

	stack = NULL;
	i = -1;
	while (++i < ac)
	{
		tmp = node_new(ft_atoi(av[i]));
		if (!tmp)
			return (NULL);
		append(&stack, tmp);
	}
	return (stack);
}
