/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:17:48 by rdupeux           #+#    #+#             */
/*   Updated: 2023/12/03 18:12:47 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup_memory(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *next;
	size_t len;

	len = get_stack_len(&stack_a);
	while (len--)
	{
		next = stack_a->next;
		free(stack_a);
		stack_a = next;
	}
	len = get_stack_len(&stack_b);
	while (len--)
	{
		next = stack_b->next;
		free(stack_b);
		stack_b = next;
	}
}

t_stack	*setup(int ac, char **av)
{
	t_stack	*a;

	if (check_input(ac, av))
	{
		ft_putstr_fd("ERROR\n", 2);
		return (NULL);
	}
	a = init_stack(ac - 1, &av[1]);
	if (!a)
		return (NULL);
	ranksort_stk(&a);
	return (a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = setup(ac, av);
	if (!stack_a)
		return (1);
	sorting(&stack_a, &stack_b);
	cleanup_memory(stack_a, stack_b);
}
