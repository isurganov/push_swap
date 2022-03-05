/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:25:36 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 21:36:04 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **s_a, char c, int *size)
{
	t_node	*first;
	t_node	*tmp;

	first = *s_a;
	if ((*s_a) != NULL && (*s_a)->next != NULL)
	{
		(*s_a) = (*s_a)->next;
		tmp = (*s_a);
		while ((*s_a)->next != NULL)
		{
			*s_a = (*s_a)->next;
		}
		(*s_a)->next = first;
		(*s_a)->next->next = NULL;
		(*s_a) = tmp;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	*size = *size + 1;
}

void	ft_rb(t_node **s_b, char c, int *size)
{
	ft_ra(s_b, c, size);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_rr(t_node **s_a, t_node **s_b, int *size, char c)
{
	ft_ra(s_a, 's', size);
	ft_ra(s_b, 's', size);
	*size = *size - 1;
	if (c == 'r')
		write(1, "rr\n", 3);
}
