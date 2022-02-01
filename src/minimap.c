/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:51:17 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/02 00:09:36 by ttanja           ###   ########.fr       */
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
				i / map->x, WHITE);
	}
}

void	draw_player_on_minimap(t_all *all)
{
	ft_mlx_pixel_put(all->win->mlx, all->win->win, all->plr->position.x,
			all->plr->position.y, RED);
}
