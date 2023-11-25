/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:17:48 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/25 14:45:15 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *stack_a;
	//t_stack *stack_b;

	if (check_input(ac, av))
		{
			ft_putstr_fd("ERROR\n",2);
			return (1);
		}
	stack_a = init_stack(ac - 1, &av[1]);
	//stack_b = NULL;
	print_stack(stack_a, 1);
}
