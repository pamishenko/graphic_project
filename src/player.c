/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:34:14 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 13:01:42 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/cub3d.h"

int	set_direction(char c, t_all *all)
{
	if (c == 'N')
	{
		all->pl.sp = 'N';
		all->pl.d = 270;
	}
	else if (c == 'E')
	{
		all->pl.sp = 'E';
		all->pl.d = 0;
	}
	else if (c == 'S')
	{
		all->pl.sp = 'S';
		all->pl.d = 90;
	}
	else if (c == 'W')
	{
		all->pl.sp = 'W';
		all->pl.d = 180;
	}
	all->pl.s = 2;
	all->pl.angle = 3;
	return (1);
}

void	set_player_pos(int x, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	all->pl.p_x = x * BLOCK_SIZE + (BLOCK_SIZE / 2);
	all->pl.p_y = all->mlx.y + (BLOCK_SIZE / 2);
	all->flag++;
	while (i < all->map.y_size)
	{
		j = 0;
		while (all->map.mp[i][j])
		{
			if (all->map.mp[i][j] == 'N' || all->map.mp[i][j] == 'S'
					|| all->map.mp[i][j] == 'W' || all->map.mp[i][j] == 'E')
				set_direction(all->map.mp[i][j], all);
			j++;
		}
		i++;
	}
}

void	search_player(t_all *all)
{
	int		x;
	int		y;

	all->flag = 0;
	y = -1;
	while (++y < all->map.y_size)
	{
		x = -1;
		all->mlx.x = 0;
		while (++x < all->map.max)
		{
			if ((all->map.mp[y][x] == 'N' || all->map.mp[y][x] == 'S'
					|| all->map.mp[y][x] == 'W'
					|| all->map.mp[y][x] == 'E') && all->flag == 0)
				set_player_pos(x, all);
		}
		all->mlx.y += BLOCK_SIZE;
	}
}
