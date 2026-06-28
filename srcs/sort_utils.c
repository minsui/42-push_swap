/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 20:12:56 by mkim2             #+#    #+#             */
/*   Updated: 2026/06/13 14:11:46 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*curr;

	curr = a->top;
	while (curr && curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	index_stack(t_stack *a)
{
	t_node	*curr;
	t_node	*compare;
	int		count;

	if (!a || !a->top)
		return ;
	curr = a->top;
	while (curr)
	{
		count = 0;
		compare = a->top;
		while (compare)
		{
			if (curr->value > compare->value)
				count++;
			compare = compare->next;
		}
		curr->index = count;
		curr = curr->next;
	}
}

int	get_min_pos_by_index(t_stack *stack, int target_index)
{
	t_node	*curr;
	int		i;

	if (!stack || !stack->top)
		return (0);
	curr = stack->top;
	i = 0;
	while (curr)
	{
		if (curr->index == target_index)
			return (i);
		curr = curr->next;
		i++;
	}
	return (0);
}
