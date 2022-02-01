/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:15:06 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/02 00:09:59 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>


void	redisplay(t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	draw_map_2d(all);
	draw_player_on_minimap(all);
}

void ft_mlx_pixel_put(void *mlx, void *win, int x, int y, int color)
{
	int i;
	int j;
	int minimap_size;

	i = 0;
	minimap_size = 5;
	while (++i <=  minimap_size)
	{
		j = 0;
		while (++j <=  minimap_size)
			mlx_pixel_put(mlx, win, x * minimap_size + j, y * minimap_size + i, color);
	}
}
