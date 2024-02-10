/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:19:59 by rdupeux           #+#    #+#             */
/*   Updated: 2024/02/10 14:22:47 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*handle_ac(char *input)
{
	char	**av;
	int		ac;
	t_stack	*stack;

	if (!ft_strlen(input))
		return (NULL);
	av = ft_split(input, ' ');
	if (!av)
		return (NULL);
	ac = 0;
	while (av[ac])
		ac++;
	stack = setup(ac, av, 0);
	cleanup_av(av);
	return (stack);
}

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
