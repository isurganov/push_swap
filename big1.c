/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:14:12 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 20:47:09 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b1(t_node **s_a, t_node **s_b, int *size, t_node **need_num)
{
	while ((*need_num)->info.rr != 0)
	{
		ft_rr(s_a, s_b, size, 'r');
		(*need_num)->info.rr--;
	}
	while ((*need_num)->info.rrr != 0)
	{
		ft_rrr(s_a, s_b, size, 'r');
		(*need_num)->info.rrr--;
	}
	while ((*need_num)->info.ra != 0)
	{
		ft_ra(s_a, 'a', size);
		(*need_num)->info.ra--;
	}
	ft_sort_b2(s_a, s_b, size, need_num);
}

void	ft_sort_b2(t_node **s_a, t_node **s_b, int *size, t_node **need_num)
{
	while ((*need_num)->info.rra != 0)
	{
		ft_rra(s_a, 'a', size);
		(*need_num)->info.rra--;
	}
	while ((*need_num)->info.rb != 0)
	{
		ft_rb(s_b, 'b', size);
		(*need_num)->info.rb--;
	}
	while ((*need_num)->info.rrb != 0)
	{
		ft_rrb(s_b, 'b', size);
		(*need_num)->info.rrb--;
	}
}

void	ft_help_count_iter_for_elem(t_node **s_a)
{
	while ((*s_a)->info.ra != 0 && (*s_a)->info.rb != 0)
	{
		(*s_a)->info.ra--;
		(*s_a)->info.rb--;
		(*s_a)->info.rr++;
	}
	while ((*s_a)->info.rra != 0 && (*s_a)->info.rrb != 0)
	{
		(*s_a)->info.rra--;
		(*s_a)->info.rrb--;
		(*s_a)->info.rrr++;
	}
	(*s_a)->info.sum = (*s_a)->info.ra + (*s_a)->info.rb
		+ (*s_a)->info.rr + (*s_a)->info.rra
		+ (*s_a)->info.rrb + (*s_a)->info.rrr;
}

void	ft_help_find_num(t_node *s_a, t_node *s_b,
		t_node *max, int *need_n)
{
	t_node	*des;
	int		i;

	i = 0;
	des = max;
	while (s_b != NULL)
	{
		if (s_a->num <= s_b->num && des->num >= s_b->num)
		{
			des = s_b;
			*need_n = i;
		}
		i++;
		s_b = s_b->next;
	}
	*need_n = *need_n + 1;
}
