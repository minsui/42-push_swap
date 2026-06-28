/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:41:59 by mkim2             #+#    #+#             */
/*   Updated: 2026/06/13 14:12:22 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

void	fill_stack(t_stack *a, int ac, char **av)
{
	int		i;
	long	val;

	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
			ft_error();
		val = ft_atoi(av[i]);
		if (val > 2147483647 || val < -2147483648)
			ft_error();
		if (is_duplicate(a, (int)val))
			ft_error();
		ft_add_back(a, ft_new_node((int)val));
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2 || av[1][0] == '\0')
		return (0);
	init_stack(&a);
	init_stack(&b);
	if (ac == 2 && has_space(av[1]))
		split_and_fill(&a, av[1]);
	else
		fill_stack(&a, ac, av);
	if (a.size == 0 || is_sorted(&a))
		return (0);
	if (a.size == 2 && a.top->value > a.top->next->value)
		sa(&a);
	else if (a.size == 3)
		sort_three(&a);
	else if (a.size <= 5 && a.size > 3)
		sort_five(&a, &b);
	else if (a.size > 5)
		large_sort(&a, &b);
}
