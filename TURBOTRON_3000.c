/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TURBOTRON_3000.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:40:49 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/30 20:44:33 by rdupeux          ###   ########.fr       */
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
			add_split(cursor, (i - 1) * (len / SPLIT_NB), i * (len / SPLIT_NB),
				i);
			cursor = cursor->next;
		}
		add_split(cursor, (i - 1) * (len / SPLIT_NB), i * (len / SPLIT_NB), i);
		i++;
	}
}

static void	phase_1_chose_move(t_stack **stack_a, t_stack **stack_b,
		unsigned int split_nb)
{
	if (!(*stack_b))
	{
		if ((*stack_a)->split == split_nb || (*stack_a)->split == split_nb + 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	else if ((*stack_a)->split == split_nb || (*stack_a)->split == split_nb + 1)
	{
		if ((*stack_b)->split == split_nb + 1 && get_stack_len(stack_b) > 1
		&& split_value_left(stack_b, split_nb, split_nb))
			rb(stack_b);
		else
			pb(stack_a, stack_b);
	}
	else if ((*stack_b)->split == split_nb + 1 && get_stack_len(stack_b) > 1)
	{
		rr(stack_a, stack_b);
	}
	else
	{
		ra(stack_a);
	}
}

static void	phase_1(t_stack **stack_a, t_stack **stack_b)
{
	static unsigned int	split_nb;

	split_nb++;
	if (split_nb > SPLIT_NB || !(*stack_a))
		return ;
	phase_1_chose_move(stack_a, stack_b, split_nb);
	while (split_value_left(stack_a, split_nb, split_nb + 1))
		phase_1_chose_move(stack_a, stack_b, split_nb);
	phase_1(stack_a, stack_b);
}

static void	phase_2(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int	rank;
	int				rotate;

	rank = get_stack_len(stack_b);
	while (*stack_b)
	{
		rotate = rr_or_r(stack_b, rank--);
		if (rotate < 0)
		{
			while (rotate++)
				rrb(stack_b);
			pa(stack_a, stack_b);
		}
		else if (rotate >= 0)
		{
			while (rotate--)
				rb(stack_b);
			pa(stack_a, stack_b);
		}
	}
}

void	TURBOTRON_3000(t_stack **stack_a, t_stack **stack_b)
{
	tag_split(stack_a);
	phase_1(stack_a, stack_b);
	phase_2(stack_a, stack_b);
	return ;
	print_stack(stack_a, 0);
	print_stack(stack_b, 0);
	print_stack(stack_a, 1);
	print_stack(stack_b, 1);
}
