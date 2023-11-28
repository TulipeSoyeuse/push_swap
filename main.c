/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:17:48 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/28 01:31:36 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *setup(int ac, char **av)
{
	t_stack *a;
		if (check_input(ac, av))
		{
			ft_putstr_fd("ERROR\n",2);
			return (NULL);
		}
	a = init_stack(ac - 1, &av[1]);
	if (!a)
		return (NULL);
	ranksort_stk(&a);
	return (a);
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	stack_a = setup(ac, av);
	if (!stack_a)
		return (1);
	print_stack(stack_a, 0);
	phase_1(&stack_a, &stack_b);
	print_stack(stack_b, 1);

}
