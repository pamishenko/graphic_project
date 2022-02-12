/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:51:17 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/12 12:05:48 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>
#include <mlx.h>
#include <math.h>

void draw_map_2d(t_all *all)
{
	t_map	*map;
	int		i;
	
	map = all->mapa;
	i = -1;
	while (map->map[++i])
	{
		if (map->map[i] == '1')
			ft_mlx_pixel_put(all->win->mlx, all->win->win, i % map->x,
				i / map->x, WHITE, BLOCK_SIZE);
	}
}


#include <stdio.h>

void	draw_player_on_minimap(t_all *all)
{
	t_plr ray;

	ray = *all->plr;
		ray.start = ray.dir - (M_PI / 6);
		ray.end = ray.dir + (M_PI / 6);	
	ft_mlx_pixel_put_pl(all->win->mlx, all->win->win, all->plr->px - PLAYER_SIZE + PLAYER_SIZE % 2,
			all->plr->py, PLAYER_SIZE);
		while (ray.start <= ray.end)
	{
		ray.dpx = all->plr->px;
		ray.dpy = all->plr->py;
		while (all->mapa->map[(all->mapa->x * ((int)(ray.dpy) / BLOCK_SIZE)) + ((int)(ray.dpx)/ BLOCK_SIZE)] != '1')
		{
			ray.dpx += cos(ray.start);
			ray.dpy += sin(ray.start);
			mlx_pixel_put(all->win->mlx, all->win->win, ray.dpx, ray.dpy, GREEN);
		}
		ray.start += (M_PI / 3 / HEIGHT);
	}

}
