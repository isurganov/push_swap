/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:23:31 by Arbiter           #+#    #+#             */
/*   Updated: 2022/03/02 20:42:07 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_separator(const char *s, char c, int i)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (j);
}

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free (str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

static char	*ft_dest(char *des, char const *s, char c, int *j)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	z = ft_separator(s, c, z);
	y = z;
	while (s[z] != c && s[z] != '\0')
	{
		x++;
		z++;
	}
	z = ft_separator(s, c, z);
	des = (char *)malloc(sizeof(char) * (x + 1));
	if (des == NULL)
		return (NULL);
	x = 0;
	while (s[y] != c && s[y] != '\0')
		des[x++] = s[y++];
	des[x] = '\0';
	*j = z;
	return (des);
}

char	**ft_split(char const *s, char c)
{
	int		x;
	int		y;
	int		z;
	char	**str;
	char	*des;

	if (s == NULL)
		return (NULL);
	des = NULL;
	x = 0;
	y = ft_count(s, c);
	str = (char **)malloc(sizeof(char *) * (y + 1));
	if (str == NULL)
		return (NULL);
	while (x < y)
	{
		str[x] = ft_dest(des, s, c, &z);
		if (str[x] == NULL)
			return (ft_free(str));
		s += z;
		x++;
	}
	str[x] = NULL;
	return (str);
}
