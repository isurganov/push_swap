/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:53:05 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 21:33:25 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_step_a(t_node *s_a, t_node *min)
{
	int	i;

	i = 0;
	while (s_a != min)
	{
		i++;
		s_a = s_a->next;
	}
	return (i);
}

void	ft_sort_middle2(t_node **s_a, int k, int i, int *size)
{
	int		h;
	t_node	*min;

	ft_min((*s_a), &min);
	h = ft_count_step_a((*s_a), min);
	if (k / 2 >= h)
	{
		while (h != 0)
		{
			ft_ra(s_a, 'a', size);
			h--;
		}
	}
	else if (k / 2 < h)
	{
		while (h != k - i)
		{
			ft_rra(s_a, 'a', size);
			h++;
		}
	}
}

void	ft_sort_middle1(t_node **s_a, t_node **s_b, int point, int *size)
{
	int	i;
	int	k;

	i = 0;
	k = ft_len_node((*s_a));
	while (i != point)
	{
		ft_sort_middle2(s_a, k, i, size);
		ft_pb(s_a, s_b, 'b', size);
		i++;
	}
}
