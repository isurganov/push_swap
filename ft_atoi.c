/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:49:03 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 18:33:12 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (!str[i])
		return (0);
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i] == '\r' \
		|| str[i] == '\f' || str[i] == ' ')
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i++] - 48);
		if (nbr > 2147483647 && sign == 1)
			return (-1);
		if (nbr > 2147483648 && sign == -1)
			return (0);
	}
	return (nbr * sign);
}

int	ft_atoi2(const char *str)
{
	long long int	i;
	int				k;
	int				j;

	i = 0;
	j = 0;
	k = 0;
	if (str[k] == '-' || str[k] == '+')
	{
		if (str[k] == '-')
			j = 1;
		k++;
	}
	while (str[k] <= '9' && str[k] >= '0')
	{
		i = i * 10 - (str[k] - '0');
		k++;
	}
	if (j == 0)
		i = -1 * i;
	if (i > 2147483647 || i < -2147483648)
		return (-2);
	return (1);
}
