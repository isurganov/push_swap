/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:16:11 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 20:24:52 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_node **s_a, char c, int *size)
{
	t_node	*tmp;

	tmp = *s_a;
	if ((*s_a) != NULL && (*s_a)->next != NULL)
	{
		(*s_a) = (*s_a)->next;
		tmp->next = (*s_a)->next;
		(*s_a)->next = tmp;
	}
	if (c == 'a')
		write(1, "sa\n", 3);
	*size = *size +1;
}

void	ft_sb(t_node **s_b, char c, int *size)
{
	ft_sa(s_b, c, size);
	if (c == 'b')
		write (1, "sb\n", 3);
}

void	ft_ss(t_node **s_a, t_node **s_b, int *size, char c)
{
	ft_sa(s_a, 's', size);
	ft_sa(s_b, 's', size);
	*size = *size - 1;
	if (c == 's')
		write(1, "ss\n", 3);
}

void	ft_pa(t_node **s_a, t_node **s_b, char c, int *size)
{
	t_node	*tmp;

	tmp = *s_b;
	if ((*s_b) != NULL)
	{
		(*s_b) = (*s_b)->next;
		tmp->next = (*s_a);
		*s_a = tmp;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	*size = *size + 1;
}

void	ft_pb(t_node **s_a, t_node **s_b, char c, int *size)
{
	ft_pa(s_b, s_a, c, size);
	if (c == 'b')
		write(1, "pb\n", 3);
}
