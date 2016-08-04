/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_opps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 20:34:14 by satkins           #+#    #+#             */
/*   Updated: 2016/08/01 20:34:16 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_addint(char curr, int i, int *mp, int width)
{
	if (curr == g_obstacle)
	{
		mp[i] = 0;
		return (1);
	}
	if (curr == g_empty)
	{
		if (mp[i - (width + 1)] <= mp[i - width]
			&& mp[i - (width + 1)] <= mp[i - 1])
			mp[i] = mp[i - (width + 1)] + 1;
		else if (mp[i - width] <= mp[i - (width + 1)]
			&& mp[i - width] <= mp[i - 1])
			mp[i] = mp[i - width] + 1;
		else
			mp[i] = mp[i - 1] + 1;
		return (1);
	}
	return (0);
}

void	ft_structhelper(t_index *max, int x, int i, int val)
{
	if (val > max[0].max)
	{
		max[0].max = val;
		max[0].x = i % x;
		max[0].y = i / x;
	}
}

t_index	*ft_create(int **newbox, char *str, int x, int y)
{
	int		i;
	int		k;
	t_index	*max;

	i = -1;
	max = (t_index *)malloc(sizeof(t_index) * 1);
	max[0].max = 0;
	while (++i < x)
		(*newbox)[i] = 0;
	k = -1;
	while (str[++k] && i / x < y)
	{
		(*newbox)[i] = 0;
		while (++i % x > 0 && str[k])
		{
			if (!ft_addint(str[k], i, *newbox, x))
				return (0);
			ft_structhelper(max, x, i, (*newbox)[i]);
			k++;
		}
		if (str[k] != '\n')
			return (0);
	}
	return (max);
}
