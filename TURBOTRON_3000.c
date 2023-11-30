/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TURBOTRON_3000.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:40:49 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/30 11:15:02 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tag_split(t_stack **stack_a)
{
	t_stack	*cursor;
	int		len;
	int		i;

	len = get_stack_len(stack_a);
	i = 1;
	while (i <= SPLIT_NB)
	{
		cursor = *stack_a;
		while (cursor->next != *stack_a)
		{
			if (cursor->rank <= (size_t)(i * (len / SPLIT_NB))
				&& cursor->rank > (size_t)((i - 1) * (len / SPLIT_NB)))
				cursor->split = i;
			cursor = cursor->next;
		}
		if (cursor->rank <= (size_t)(i * (len / SPLIT_NB))
			&& cursor->rank > (size_t)(i - 1) * (len / SPLIT_NB))
			cursor->split = i;
	}
}

static int	rr_or_r_range(t_stack **stack, unsigned int split_nb)
{
	t_stack			*cursor_f;
	t_stack			*cursor_b;
	int				rotate;
	unsigned int	split_nb2;

	if (split_nb < SPLIT_NB)
		split_nb2 = split_nb + 1;
	else
		split_nb2 = 0;
	cursor_f = *stack;
	cursor_b = (*stack);
	rotate = 0;
	while (cursor_f->next != (*stack) && cursor_b->prev != *stack)
	{
		if (cursor_f->split == split_nb || cursor_f->split == split_nb2)
			return (rotate);
		if (cursor_b->split == split_nb || cursor_b->split == split_nb2)
			return (-rotate);
		rotate++;
		cursor_f = cursor_f->next;
		cursor_b = cursor_b->prev;
	}
	return (0);
}

static void	phase_1(t_stack **stack_a, t_stack **stack_b)
{
	int	rotate;
	//int	split_nb;
	//int	count;

	rotate = rr_or_r_range(stack_a, 1);
	while (*stack_a)
	{
		rotate = rr_or_r_range(stack_a, 1);
		if (rotate < 0)
		{
			while (rotate++)
				rra(stack_a);
			pb(stack_a, stack_b);
		}
		else if (rotate >= 0)
		{
			while (rotate--)
				ra(stack_a);
			pb(stack_a, stack_b);
		}
	}
}

void	TURBOTRON_3000(t_stack **stack_a, t_stack **stack_b)
{
	size_t	moved;

	tag_split(stack_a);
	phase_1(stack_a, stack_b);
}
