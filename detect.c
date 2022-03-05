/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:57:14 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 18:32:48 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_detect_target_num(t_node *s_a, t_node **target)
{
	(*target) = NULL;
	while (s_a != NULL)
	{
		if ((*target) == NULL || s_a->info.sum < (*target)->info.sum)
		{
			(*target) = s_a;
		}
		s_a = s_a->next;
	}
}

void	ft_max(t_node *s, t_node **max)
{
	*max = NULL;
	while (s != NULL)
	{
		if ((*max) == NULL || s->num > (*max)->num)
			*max = s;
		s = s->next;
	}
}

void	ft_min(t_node *s, t_node **min)
{
	*min = NULL;
	while (s != NULL)
	{
		if ((*min) == NULL || s->num < (*min)->num)
			*min = s;
		s = s->next;
	}
}

t_node	*ft_last(t_node *s)
{
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
	}
	return (s);
}
