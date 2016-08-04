/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 14:59:32 by satkins           #+#    #+#             */
/*   Updated: 2016/08/03 23:14:40 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H

# define FT_BSQ_H

# include <stdlib.h>

# include <fcntl.h>

# include <unistd.h>

# define BUFF_SIZE 9000

extern char		g_empty;

extern char		g_obstacle;

extern char		g_full;

extern int		g_rows;

typedef struct	s_index
{
	int x;
	int y;
	int max;
	int i;
}				t_index;

t_index			*ft_create(int **newbox, char *str, int x, int y);

void			ft_maxfind(int ***map, char *str, int x, int y);

void			ft_putchar(char c);

void			ft_strcpy(char *src, char *dest);

void			ft_strconcat(char *dest, char *src);

int				ft_atoi(char *str);

#endif
