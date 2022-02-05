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
	if (all->mapa->map[all->mapa->x * all->mapa->y / py/MAP_SIZE + px/MAP_SIZE] == '1')	
		return (1);
	return (0);
}

t_plr *pl;

int	buttons(int key, t_all *all)
{
	pl = all->plr;
	if (key == A) {pl->dir -= 0.1; if (pl->dir < 0){pl->dir+=2*M_PI;} pl->dpx = cos(pl->dir); pl->dpy = sin(pl->dir);}
	if (key == D) {pl->dir += 0.1; if (pl->dir > 2 * M_PI){pl->dir-=2*M_PI;} pl->dpx = cos(pl->dir); pl->dpy = sin(pl->dir);}
	if (key == W && is_wall(pl->px + pl->dpx * 3, pl->py + pl->dpy * 3, all)) {pl->px += pl->dpx * 3; pl->py += pl->dpy * 3;}
	if (key == S && is_wall(pl->px - pl->dpx * 3, pl->py - pl->dpy * 3, all)) {pl->px -= pl->dpx * 3; pl->py -= pl->dpy * 3;}
	redisplay(all);
	printf("dpx - %f      dpy - %f\n", pl->dpx, pl->dpy);
	return (0);
}