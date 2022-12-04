/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:25:31 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 13:28:47 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include "../includes/cub3d.h"
#include "../includes/defines.h"
#include "../includes/mlx.h"

float	phifagor(float x, float y, float xd, float yd)
{
	return (sqrt(pow((xd - x), 2) + pow(yd - y, 2)));
}

int	get_comma_count(char *str)
{
	int	i;
	int	count_comm;

	i = -1;
	count_comm = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			count_comm++;
	}
	return (count_comm);
}

void	set_max_map_line(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	all->map.max = 0;
	while (++i < all->map.y_size)
	{
		j = 0;
		while (all->map.mp[i][j])
			j++;
		if (j > all->map.max)
			all->map.max = j;
	}
}
