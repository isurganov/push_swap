/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:09:08 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 21:35:48 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_front_sort(t_node *s_a, int argc)
{
	int	tmp;
	int	i;

	i = 0;
	if (s_a == NULL)
		return (1);
	tmp = s_a->num;
	while (s_a != NULL)
	{
		if (s_a->num >= tmp)
			tmp = s_a->num;
		else if (i < argc)
			return (1);
		i++;
		s_a = s_a->next;
	}
	if (i < argc)
		return (1);
	return (0);
}

int	ft_back_sort(t_node *s_b, int argc)
{
	int	tmp;
	int	i;

	i = 0;
	if (s_b == NULL)
		return (1);
	tmp = s_b->num;
	while (s_b != NULL)
	{
		if (s_b->num <= tmp)
			tmp = s_b->num;
		else if (i < argc)
			return (1);
		i++;
		s_b = s_b->next;
	}
	if (i < argc)
		return (1);
	return (0);
}

int	ft_isnum(char *arg)
{
	int	check;
	int	i;

	check = 1;
	i = 0;
	while (arg[i] == ' ')
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] != '\0')
	{
		check = ft_isdigit(arg[i]);
		if (check == 0)
			break ;
		i++;
	}
	if (i > 12)
		check = 0;
	return (check);
}

void	ft_check_node(t_node *s_a)
{
	t_node	*tmp;
	t_node	*des;

	tmp = s_a;
	while (tmp != NULL)
	{
		des = s_a;
		while (des != NULL)
		{
			if (tmp != des && tmp->num == des->num)
				ft_error(5);
			des = des->next;
		}
		tmp = tmp->next;
	}
}

void	ft_new_node(t_node **s_a, int argc, char **argv)
{
	t_node	*tmp;

	tmp = NULL;
	argc--;
	while (argc != 0)
	{
		*s_a = (t_node *)malloc(sizeof(t_node));
		if (*s_a == NULL)
			ft_error(4);
		if (ft_isnum(argv[argc]) == 0)
			ft_error(3);
		if (ft_atoi2(argv[argc]) == -2)
			ft_error(3);
		(*s_a)->num = ft_atoi(argv[argc]);
		(*s_a)->next = tmp;
		tmp = *s_a;
		argc--;
	}
}
