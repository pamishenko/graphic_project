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




t_plr *pl;

int	buttons(int key, t_all *all)
{
	pl = all->plr;
	if (key == A) {
		pl->dir -= 0.05;
		if (pl->dir < 0){
			pl->dir+=2*M_PI;
			}
		pl->dpx = cos(pl->dir);
		pl->dpy = sin(pl->dir);
	}
	if (key == D) {pl->dir += 0.05; if (pl->dir > 2 * M_PI){pl->dir-=2*M_PI;} pl->dpx = cos(pl->dir); pl->dpy = sin(pl->dir);}
	if (key == W) {pl->px += cos(pl->dir) * 20; pl->py += sin(pl->dir) * 20;}
	if (key == S) {pl->px -= cos(pl->dir) * 20; pl->py -= sin(pl->dir) * 20;}
	redisplay(all);
	return (0);
}