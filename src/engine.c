/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:15:06 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/05 22:51:51 by ttanja           ###   ########.fr       */
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
	draw_rays_3d(all);
}

void ft_mlx_pixel_put(void *mlx, void *win, int x, int y, int color, int s)
{
	int i;
	int j;

	i = 0;
	while (++i <=  s)
	{
		j = 0;
		while (++j <=  s)
			mlx_pixel_put(mlx, win, x * s + j, y * s + i, color);
	}
}

void ft_mlx_pixel_put_pl(void *mlx, void *win, int x, int y, int s)
{
	int i;
	int j;

	i = 0;
	while (++i <=  s)
	{
		j = 0;
		while (++j <=  s)
			mlx_pixel_put(mlx, win, x + j + (s %2), y + i - (s / 2), RED);
	}
}
