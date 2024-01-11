/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:17:48 by rdupeux           #+#    #+#             */
/*   Updated: 2024/01/10 15:16:53 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	cleanup_av(char **av)
{
	char **a;

	a = av;
	while (*av)
	{
		free(*av);
		av++;
	}
	free(a);
}

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

t_stack	*setup(int ac, char **av, int start)
{
	t_stack	*a;

	if (check_input(ac - start , &av[start]))
		error();
	a = init_stack(ac - start, &av[start]);
	if (!a)
		return (NULL);
	ranksort_stk(&a);
	return (a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (!ft_strlen(av[1]))
			error();
		av = ft_split(av[1],' ');
		if (!av)
			return (1);
		ac = 0;
		while (av[ac])
			ac++;
		stack_a = setup(ac, av, 0);
		cleanup_av(av);
	}
	else
		stack_a = setup(ac, av, 1);
	stack_b = NULL;
	if (!stack_a)
		return (1);
	sorting(&stack_a, &stack_b);
	cleanup_memory(stack_a, stack_b);
}
