/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:21:48 by mkim2             #+#    #+#             */
/*   Updated: 2026/04/09 18:36:20 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dest, t_stack *src)
{
	t_node	*tmp;

	if (!src || src->size == 0 || !src->top)
		return ;
	tmp = src->top;
	src->top = tmp->next;
	if (src->top)
		src->top->prev = NULL;
	src->size--;
	tmp->next = dest->top;
	if (dest->top)
		dest->top->prev = tmp;
	dest->top = tmp;
	dest->top->prev = NULL;
	dest->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
