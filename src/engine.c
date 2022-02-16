/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:15:06 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/13 16:53:50ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>


int	redisplay(t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	floor_and_ceiling(all);
	draw_3d(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->data->img, 0, 0);
	// draw_map_2d(all);
	// draw_player_on_minimap(all);
	usleep(1000 / 60);
	return (0);
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

void	draw_3d(t_all *all)
{
	t_plr ray;
	int x;

	x = 0;
	ray = *all->plr;
	ray.start = ray.dir - (M_PI / 6);
	ray.end = ray.dir + (M_PI / 6);	
	  
	while (ray.start <= ray.end)
	{
		ray.dpx = all->plr->px;
		ray.dpy = all->plr->py;
		while (all->mapa->map[(all->mapa->x * ((int)(ray.dpy) / BLOCK_SIZE)) + ((int)(ray.dpx)/ BLOCK_SIZE)] != '1')
		{
			ray.dpx += cos(ray.start);
			ray.dpy += sin(ray.start);
		}
		float len = (sqrt((all->plr->px - (int)ray.dpx) * (all->plr->px - (int)ray.dpx)
			+ (all->plr->py - (int)ray.dpy) * (all->plr->py - (int)ray.dpy)) * cos(ray.start - ray.dir)) / 100;
		x++;
		int i = 0;
			while (i++ < WIDTH / len)
				my_mlx_pixel_put(all->data, x , i + (WIDTH - (WIDTH / len)) / 2, RED);
		ray.start += (M_PI / 3 / HEIGHT);
	}
}
