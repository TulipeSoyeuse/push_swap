/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:19:04 by rdupeux           #+#    #+#             */
/*   Updated: 2023/12/03 17:23:05 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef SPLIT_NB
#  define SPLIT_NB 10
# endif
# include "libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				value;
	size_t			rank;
	unsigned int	split;
}					t_stack;

t_stack				*node_new(int content);
int					check_input(size_t ac, char **av);
t_stack				*init_stack(int ac, char **av);
void				print_stack(t_stack **stack, int del);
void				ranksort_stk(t_stack **stack);
size_t				get_stack_len(t_stack **stack);
void				cleanup_memory(t_stack *stack_a, t_stack *stack_b);

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

int					split_value_left(t_stack **stack, unsigned int split_nb,
						unsigned int split_nb_2);
void				phase_2_rotate(t_stack **stack_a, t_stack **stack_b,
						int rank);
void				add_split(t_stack *stack, float min, float max, int split);
int					rr_or_r(t_stack **stack, size_t rank);
void				sorting(t_stack **stack_a, t_stack **stack_b);
void				turbotron_3000(t_stack **stack_a, t_stack **stack_b);
#endif
