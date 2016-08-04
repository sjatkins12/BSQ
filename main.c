/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 14:57:12 by satkins           #+#    #+#             */
/*   Updated: 2016/08/01 14:57:13 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char g_empty;

char g_obstacle;

char g_full;

int g_rows;

void	ft_print(t_index *max, char *str, int width)
{
	int k;
	int n;

	n = 0;
	while (n < max->max)
	{
		k = 0;
		while (k < max->max)
		{
			str[width * (max->y - 1) + (max->x - 1)] = g_full;
			k++;
			max->x--;
		}
		max->y--;
		max->x += max->max;
		n++;
	}
	free(max);
	write(1, str, width * g_rows);
}

int		ft_advancestr(char **str)
{
	int i;

	i = 0;
	if (!(g_rows = ft_atoi(*str)))
	{
		write(1, "map error\n", 10);
		return (0);
	}
	while ((*str)[i] != '\n')
		i++;
	g_full = (*str)[i - 1];
	g_obstacle = (*str)[i - 2];
	g_empty = (*str)[i - 3];
	while (**str >= '0' && **str <= '9')
		*str += 1;
	while ((*str)[3] != '\n')
	{
		g_rows /= 10;
		*str -= 1;
	}
	*str += 4;
	return (1);
}

int		ft_readbuff(char **str, int fd)
{
	int		leng;
	int		size;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	size = 0;
	*str = (char *)malloc(sizeof(char) * (1));
	tmp = (char *)malloc(sizeof(char) * (1));
	tmp[0] = 0;
	*str[0] = 0;
	while ((leng = read(fd, buff, BUFF_SIZE) && *str && tmp))
	{
		size += BUFF_SIZE;
		ft_strcpy(*str, tmp);
		*str = (char *)malloc(sizeof(char) * (size + 1));
		ft_strcpy(tmp, *str);
		ft_strconcat(*str, buff);
		tmp = (char *)malloc(sizeof(char) * (size + 1));
		(*str)[size] = '\0';
	}
	free(tmp);
	if (!(ft_advancestr(str)))
		return (0);
	close(fd);
	return (1);
}

void	ft_count_width(char *str)
{
	int		*box;
	int		width;
	t_index	*max;

	width = 0;
	while (str[width] != '\n')
		width += 1;
	box = malloc(sizeof(int) * (g_rows + 1) * (width + 1));
	if (width > 0 && (max = ft_create(&box, str, width + 1, g_rows + 1)))
	{
		free(box);
		ft_print(max, str, (width + 1));
	}
	else
		write(1, "map error\n", 10);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*buff;
	int		j;

	j = 0;
	if (ac != 1)
	{
		while (++j < ac)
		{
			fd = open(av[j], O_RDONLY);
			if (fd > 0)
			{
				if (ft_readbuff(&buff, fd))
					ft_count_width(buff);
			}
			else
				write(1, "map error\n", 10);
		}
	}
	else
	{
		if (ft_readbuff(&buff, 0))
			ft_count_width(buff);
	}
	return (0);
}
