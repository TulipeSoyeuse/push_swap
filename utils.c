/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:36:31 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/30 19:38:09 by rdupeux          ###   ########.fr       */
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

static int	cleanup(int *list, int return_code)
{
	free(list);
	return (return_code);
}

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

void	print_stack(t_stack **stack, int del)
{
	t_stack	*tmp;
	t_stack	*cursor;

	if (!(*stack))
		return ;
	cursor = (*stack);
	while (cursor->next != (*stack))
	{
		printf("|%d-%zu-%d|\n", cursor->value, cursor->rank, cursor->split);
		tmp = cursor;
		cursor = cursor->next;
		if (del)
			free(tmp);
	}
	printf("|%d-%zu-%d|\n", cursor->value, cursor->rank, cursor->split);
	printf("|____|\n\n");
}
size_t get_stack_len(t_stack **stack)
{
	t_stack *cursor;
	size_t len;

	cursor = *stack;
	len = 1;
	if (!(*stack))
		return (0);
	while (cursor->next != *stack)
	{
		len++;
		cursor = cursor->next;
	}
	return (len);
}
