/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:36:31 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/25 14:48:44 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_val(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}

static int cleanup(int *list, int return_code)
{
	free(list);
	return (return_code);
}

//TODO:cleanup malloc
int	check_input(size_t ac, char **av)
{
	int		*list;
	size_t	i;
	size_t	j;
	list = malloc(sizeof(int) * ac - 1);
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (check_val(av[i]))
			return (cleanup(list, 1));
		list[j++] = ft_atoi(av[i++]);
	}
	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
			if (list[j++] == list[i])
				return (cleanup(list, 1));
		i++;
	}
	return (cleanup(list, 0));
}

void	print_stack(t_stack *stack, int del)
{
	t_stack *tmp;
	while (stack->next)
	{
		printf("|%d|\n", stack->value);
		tmp = stack;
		stack = stack->next;
		if (del)
			free(tmp);
	}
	printf("|%d|\n", stack->value);
	printf("|_|\n");
}
