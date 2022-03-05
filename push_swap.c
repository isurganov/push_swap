/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:26:02 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 20:45:21 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big(t_node **s_a, t_node **s_b, int argc, int *size)
{
	int	i;

	i = ft_front_sort(*s_a, argc);
	if (i == 1)
	{
		ft_sort_b(s_a, s_b, size);
		ft_rot_b(s_b, argc, size);
		while ((*s_b) != NULL)
			ft_pa(s_a, s_b, 'a', size);
	}
}

void	ft_sort_small(t_node **s_a, int *size, int argc)
{
	t_node	*last;
	int		i;

	last = ft_last((*s_a));
	i = ft_front_sort((*s_a), argc);
	while (i == 1)
	{
		if ((*s_a)->num > (*s_a)->next->num)
			ft_ra(s_a, 'a', size);
		else if ((*s_a)->next->num > last->num)
			ft_rra(s_a, 'a', size);
		i = ft_front_sort((*s_a), argc);
		if (i == 1)
			ft_sa(s_a, 'a', size);
		i = ft_front_sort((*s_a), argc);
	}
}

void	ft_sort_middle(t_node **s_a, t_node **s_b, int argc, int *size)
{
	int	point;

	if (argc <= 3)
	{
		ft_sort_small(s_a, size, argc);
		return ;
	}
	if (argc == 4)
		point = 1;
	if (argc == 5)
		point = 2;
	if (argc == 6)
		point = 3;
	ft_sort_middle1(s_a, s_b, point, size);
	ft_sort_small(s_a, size, argc - point);
	while ((*s_b) != NULL)
		ft_pa(s_a, s_b, 'a', size);
}

int	main(int argc, char **argv)
{
	t_node	*s_a;
	t_node	*s_b;
	int		size;
	int		i;

	s_a = NULL;
	s_b = NULL;
	size = 0;
	if (argc == 1)
		exit(2);
	if (argc == 2)
		argc = ft_new_stack1(&s_a, argv) + 1;
	else
		ft_new_node(&s_a, argc, argv);
	ft_check_node(s_a);
	i = ft_front_sort(s_a, argc - 1);
	if (i == 1)
	{
		if (argc - 1 <= 6)
			ft_sort_middle(&s_a, &s_b, argc - 1, &size);
		else
			ft_sort_big(&s_a, &s_b, argc - 1, &size);
	}
	ft_free_memory(&s_a);
	return (0);
}
