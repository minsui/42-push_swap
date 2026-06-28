/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:19:46 by mkim2             #+#    #+#             */
/*   Updated: 2026/03/20 13:16:29 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_add_back(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	if (stack->top == NULL)
	{
		stack->top = new;
	}
	else
	{
		last = stack->top;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
	stack->size++;
}
