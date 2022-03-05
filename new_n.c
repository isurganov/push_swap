/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:02:04 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 20:15:52 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

int	ft_new_stack1(t_node **s_a, char **argv)
{
	t_node	*tmp;
	char	**arg;
	int		argc;
	int		i;

	tmp = NULL;
	arg = ft_split(argv[1], ' ');
	argc = ft_len_arg(arg);
	i = argc;
	i--;
	while (i >= 0)
	{
		*s_a = (t_node *)malloc(sizeof(t_node));
		if (*s_a == NULL)
			ft_error(4);
		if (ft_isnum(arg[i]) == 0)
			ft_error(3);
		if (ft_atoi2(arg[i]) == -2)
			ft_error(3);
		(*s_a)->num = ft_atoi(arg[i]);
		(*s_a)->next = tmp;
		tmp = *s_a;
		i--;
	}
	return (argc);
}
