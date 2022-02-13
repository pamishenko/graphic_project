/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:11:41 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/05 11:01:56y ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>

#include <cub3d.h>


int	is_wall(int px, int py, t_all *all)
{
	if (all->mapa->map[all->mapa->x * py/MAP_SIZE + px/MAP_SIZE] == '1')	
		return (1);
	return (1);
}

t_plr *pl;

int	buttons(int key, t_all *all)
{
	pl = all->plr;
	if (key == A) {
		pl->dir -= 0.01;
		if (pl->dir < 0){
			pl->dir+=2*M_PI;
			}
		pl->dpx = cos(pl->dir);
		pl->dpy = sin(pl->dir);
	}
	if (key == D) {pl->dir += 0.01; if (pl->dir > 2 * M_PI){pl->dir-=2*M_PI;} pl->dpx = cos(pl->dir); pl->dpy = sin(pl->dir);}
	if (key == W && is_wall(pl->px + cos(pl->dir) * 50, pl->py + sin(pl->dir) * 50, all)) {pl->px += cos(pl->dir) * 50; pl->py += sin(pl->dir) * 50;}
	if (key == S && is_wall(pl->px - cos(pl->dir) * 50, pl->py - sin(pl->dir) * 50, all)) {pl->px -= cos(pl->dir) * 50; pl->py -= sin(pl->dir) * 50;}
	redisplay(all);
	return (0);
}