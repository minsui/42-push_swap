/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:20:26 by mkim2             #+#    #+#             */
/*   Updated: 2026/04/08 19:31:46 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

int	get_min_pos(t_stack *stack)
{
	t_node		*curr;
	int			min;
	int			pos;
	int			i;

	curr = stack->top;
	min = curr->value;
	pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->value < min)
		{
			min = curr->value;
			pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 3)
	{
		pos = get_min_pos(a);
		if (pos <= a->size / 2)
			while (pos--)
				ra(a);
		else
		{
			pos = a->size - pos;
			while (pos--)
				rra(a);
		}
		pb(b, a);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
