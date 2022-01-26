/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:11:41 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/26 19:44:32 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>

#include <cub3d.h>

int	move(int key, t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	draw_mini_map(all);
	if(key == W && !check_wall(all, 0, -1))
	{
		all->plr->curent_position.y += cos(all->plr->dir) * all->plr->speed;
		all->plr->curent_position.x += sin(all->plr->dir) * all->plr->speed;
	}
	else if(key == S && !check_wall(all, 0, 1))
	{
		all->plr->curent_position.y -= cos(all->plr->dir) * all->plr->speed * 0.5;
		all->plr->curent_position.x -= sin(all->plr->dir) * all->plr->speed * 0.5;
	}
	else if(key == A && !check_wall(all, -1, 0))
	{
		all->plr->curent_position.y += cos(all->plr->dir * M_PI_2) * all->plr->speed * 0.8;
		all->plr->curent_position.x += sin(all->plr->dir * M_PI_2) * all->plr->speed * 0.8;
	}
	else if(key == D && !check_wall(all, 1, 0))
	{
		all->plr->curent_position.y -= cos(all->plr->dir * M_PI_2) * all->plr->speed * 0.8;
		all->plr->curent_position.x -= sin(all->plr->dir * M_PI_2) * all->plr->speed * 0.8;
	}
	else if(key == LEFT && !check_wall(all, -1, 0))
		all->plr->dir += 0.05;
	else if(key == RIGHT && !check_wall(all, 1, 0))
		all->plr->dir -= 0.05;
	else if (key == ESC)
	{
		mlx_destroy_window(all->win->mlx, all->win->win);
		exit (0);
	}
	ft_cast_rays(all);
	return (0);
}