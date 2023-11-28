/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:19:04 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/28 01:18:44 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SLIPT_NB 3
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
	size_t			rank;
}					t_stack;

t_stack				*node_new(int content);
int					check_input(size_t ac, char **av);
t_stack				*init_stack(int ac, char **av);
void				print_stack(t_stack *stack, int del);
void				ranksort_stk(t_stack **stack);
size_t				get_stack_len(t_stack **stack);

void				appendleft(t_stack **stack, t_stack *to_append);
t_stack				*popleft(t_stack **stack);
void				append(t_stack **stack, t_stack *to_append);
t_stack				*pop(t_stack **stack);

void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

void				phase_1(t_stack **stack_a, t_stack **stack_b);
#endif
