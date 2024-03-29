/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:17:48 by rdupeux           #+#    #+#             */
/*   Updated: 2024/02/15 11:24:37 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	cleanup_av(char **av)
{
	char	**a;

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
	t_stack	*next;
	size_t	len;

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

	if (check_input(ac - start, &av[start]))
		return (NULL);
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
		stack_a = handle_ac(av[1]);
	else
		stack_a = setup(ac, av, 1);
	stack_b = NULL;
	if (!stack_a)
		error();
	sorting(&stack_a, &stack_b);
	cleanup_memory(stack_a, stack_b);
}
