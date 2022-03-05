/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:19:05 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 21:33:25 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_node(t_node *s)
{
	int	i;

	i = 0;
	while (s != NULL)
	{
		s = s->next;
		i++;
	}
	return (i);
}

void	ft_error(int a)
{
	write(1, "Error\n", 6);
	exit(a);
}

void	ft_init_info(t_node **s_a)
{
	(*s_a)->info.ra = 0;
	(*s_a)->info.rb = 0;
	(*s_a)->info.rr = 0;
	(*s_a)->info.rra = 0;
	(*s_a)->info.rrb = 0;
	(*s_a)->info.rrr = 0;
	(*s_a)->info.sum = 0;
}

void	ft_free_memory(t_node **s_a)
{
	t_node	*tmp;

	if (*s_a != NULL)
	{
		while ((*s_a)->next != NULL)
		{
			tmp = *s_a;
			*s_a = (*s_a)->next;
			free(tmp);
		}
		free(*s_a);
	}
}
