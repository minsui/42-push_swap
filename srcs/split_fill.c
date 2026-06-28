/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 13:59:41 by mkim2             #+#    #+#             */
/*   Updated: 2026/06/13 14:00:09 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_word(t_stack *a, char *word, int wi)
{
	long	val;

	if (wi == 0)
		return ;
	word[wi] = '\0';
	if (!is_number(word))
		ft_error();
	val = ft_atoi(word);
	if (val > 2147483647 || val < -2147483648)
		ft_error();
	if (is_duplicate(a, (int)val))
		ft_error();
	ft_add_back(a, ft_new_node((int)val));
}

void	split_and_fill(t_stack *a, char *str)
{
	char	word[32];
	int		wi;

	wi = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
		{
			process_word(a, word, wi);
			wi = 0;
		}
		else
		{
			if (wi >= 31)
				ft_error();
			word[wi++] = *str;
		}
		str++;
	}
	process_word(a, word, wi);
}

int	has_space(char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			return (1);
		str++;
	}
	return (0);
}
