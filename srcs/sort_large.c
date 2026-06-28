/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:11:17 by mkim2             #+#    #+#             */
/*   Updated: 2026/04/09 18:24:56 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *a, t_stack *b, int chunk)
{
	int	i;

	i = 0;
	while (a->size > 0)
	{
		if (a->top->index <= i)
		{
			pb(b, a);
			i++;
		}
		else if (a->top->index <= i + chunk)
		{
			pb(b, a);
			rb(b);
			i++;
		}
		else
		{
			ra(a);
		}
	}
}

void	push_to_a(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->size > 0)
	{
		pos = get_min_pos_by_index(b, b->size - 1);
		if (pos <= b->size / 2)
			while (pos--)
				rb(b);
		else
		{
			pos = b->size - pos;
			while (pos--)
				rrb(b);
		}
		pa(a, b);
	}
}

void	large_sort(t_stack *a, t_stack *b)
{
	int	chunk;

	index_stack(a);
	if (a->size <= 100)
		chunk = 15;
	else
		chunk = 30;
	push_to_b(a, b, chunk);
	push_to_a(a, b);
}
