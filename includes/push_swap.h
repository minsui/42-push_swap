/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:41:37 by mkim2             #+#    #+#             */
/*   Updated: 2026/06/13 14:12:02 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

void	split_and_fill(t_stack *a, char *str);
int		has_space(char *str);

void	init_stack(t_stack *stack);
void	fill_stack(t_stack *a, int ac, char **av);
t_node	*ft_new_node(int value);
void	ft_add_back(t_stack *stack, t_node *new);

long	ft_atoi(const char *str);
void	ft_error(void);

int		is_number(char *str);
int		is_duplicate(t_stack *a, int n);

void	swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	push(t_stack *dest, t_stack *src);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);

void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	sort_three(t_stack *a);
int		get_min_pos(t_stack *stack);
void	sort_five(t_stack *a, t_stack *b);

int		is_sorted(t_stack *a);
void	index_stack(t_stack *a);
int		get_min_pos_by_index(t_stack *stack, int target_index);

void	push_to_b(t_stack *a, t_stack *b, int chunk);
void	push_to_a(t_stack *a, t_stack *b);
void	large_sort(t_stack *a, t_stack *b);

#endif