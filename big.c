/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:37:27 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 21:33:25 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_num_b(t_node *s_a, t_node *s_b, int *target)
{
	t_node	*min;
	t_node	*max;

	*target = 0;
	ft_min(s_b, &min);
	ft_max(s_b, &max);
	if (s_a->num < min->num)
	{
		while (s_b != NULL && s_b->num >= min->num && s_b->num != max->num)
		{
			*target = *target + 1;
			s_b = s_b->next;
		}
	}
	else if (s_a->num > max->num)
	{
		while (s_b != NULL && s_b->num < max->num)
		{
			*target = *target + 1;
			s_b = s_b->next;
		}
	}
	else
		ft_help_find_num(s_a, s_b, max, target);
}

void	ft_rot_b(t_node **s_b, int argc, int *size)
{
	t_node	*max;
	t_node	*tmp;
	int		i;

	ft_max((*s_b), &max);
	tmp = (*s_b);
	i = 0;
	while ((*s_b) != NULL)
	{
		if ((*s_b) == max)
			break ;
		i++;
		(*s_b) = (*s_b)->next;
	}
	(*s_b) = tmp;
	if (i < argc / 2)
	{
		while ((*s_b) != max)
			ft_rb(s_b, 'b', size);
	}
	else
	{
		while ((*s_b) != max)
			ft_rrb (s_b, 'b', size);
	}
}

void	ft_sort_small1(t_node **s_b, int *size, int argc)
{
	t_node	*last;
	int		i;

	last = ft_last((*s_b));
	i = ft_back_sort((*s_b), argc);
	while (i == 1)
	{
		if ((*s_b)->num < (*s_b)->next->num)
			ft_rb(s_b, 'b', size);
		else if ((*s_b)->next->num < last->num)
		i = ft_front_sort((*s_b), argc);
		if (i == 1)
			ft_sb(s_b, 'b', size);
		i = ft_back_sort((*s_b), argc);
	}
}

void	ft_count_iter(t_node **s_a, t_node **s_b, int a, int b)
{
	t_node	*tmp;
	int		need_n;
	int		i;

	i = 0;
	tmp = *s_a;
	while ((*s_a) != NULL)
	{
		ft_init_info(s_a);
		ft_find_num_b((*s_a), (*s_b), &need_n);
		if (b / 2 >= need_n)
		(*s_a)->info.rb = need_n;
		if (b / 2 < need_n)
			(*s_a)->info.rrb = b - need_n;
		if (a / 2 >= i)
			(*s_a)->info.ra = i;
		if (a / 2 < i)
			(*s_a)->info.rra = a - i;
		ft_help_count_iter_for_elem(s_a);
		(*s_a) = (*s_a)->next;
		i++;
	}
	(*s_a) = tmp;
}

void	ft_sort_b(t_node **s_a, t_node **s_b, int *size)
{
	t_node	*need_num;
	int		i;
	int		a;
	int		b;

	i = 0;
	while (i != 3)
	{
		ft_pb(s_a, s_b, 'b', size);
		i++;
	}
	ft_sort_small1(s_b, size, i);
	while ((*s_a) != NULL)
	{
		a = ft_len_node(*s_a);
		b = ft_len_node(*s_b);
		ft_count_iter(s_a, s_b, a, b);
		ft_detect_target_num((*s_a), &need_num);
		ft_sort_b1(s_a, s_b, size, &need_num);
		ft_pb(s_a, s_b, 'b', size);
	}
}
