/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:51:17 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/05 18:24:44 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>
#include <mlx.h>

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
	ft_mlx_pixel_put_pl(all->win->mlx, all->win->win, all->plr->px - PLAYER_SIZE + PLAYER_SIZE % 2,
			all->plr->py - PLAYER_SIZE + PLAYER_SIZE % 2 , PLAYER_SIZE, 1);
	for (int i = 1; ; i++)
	{
		// if ()
		mlx_pixel_put(all->win->mlx, all->win->win, all->plr->px + all->plr->dpx * i,
			all->plr->py + all->plr->dpy * i, YELLOW);
	}
}
