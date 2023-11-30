/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:05:29 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/30 20:50:32 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	phase_2_rotate(t_stack **stack_a, t_stack **stack_b, int rank)
{
	int	rotate;

	rotate = rr_or_r(stack_a, rank);
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
