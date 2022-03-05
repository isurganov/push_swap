/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:25:11 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 20:46:14 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_node **s_a, char c, int *size)
{
	t_node	*last;
	t_node	*tmp;

	tmp = *s_a;
	if ((*s_a) != NULL && (*s_a)->next != NULL)
	{
		while ((*s_a)->next != NULL)
		{
			if ((*s_a)->next->next == NULL)
				last = *s_a;
			*s_a = (*s_a)->next;
		}
		(*s_a)->next = tmp;
		last->next = NULL;
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	*size = *size + 1;
}

void	ft_rrb(t_node **s_b, char c, int *size)
{
	ft_rra(s_b, c, size);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_node **s_a, t_node **s_b, int *size, char c)
{
	ft_rra(s_a, 's', size);
	ft_rra(s_b, 's', size);
	*size = *size - 1;
	if (c == 'r')
		write(1, "rrr\n", 4);
}
