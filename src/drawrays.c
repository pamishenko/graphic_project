/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:55:37 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 14:41:54 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include "../includes/cub3d.h"
#include "../includes/defines.h"
#include "../includes/mlx.h"

void	norm_kostyl(t_all *a)
{
	while (a->draws.nhorx >= 0 && a->draws.nhorx <= a->map.max * BLOCK_SIZE
		&& a->draws.nhory >= 0 && a->draws.nhory <= a->map.y_size * BLOCK_SIZE)
	{
		if (!(iswal(a->draws.nhory, a->draws.nhorx - a->draws.tchk, a)))
		{
			a->draws.vwallhit = 1;
			a->draws.vwhitx = a->draws.nhorx;
			a->draws.vwhity = a->draws.nhory;
			break ;
		}
		else
		{
			a->draws.nhorx += a->draws.spsx;
			a->draws.nhory += a->draws.spsy;
		}
	}
}

void	draw_2(int i, t_all *a)
{
	if (a->rays[i].left)
		a->draws.tchk = 1;
	else
		a->draws.tchk = 0;
	a->draws.intx = floor(a->pl.p_x / BLOCK_SIZE) * BLOCK_SIZE;
	if (a->rays[i].right)
		a->draws.intx += BLOCK_SIZE;
	a->draws.inty = a->pl.p_y - (a->pl.p_x - a->draws.intx)
		* tan(a->draws.r_ang);
	a->draws.spsx = BLOCK_SIZE;
	if (a->rays[i].left)
		a->draws.spsx *= -1;
	a->draws.spsy = a->draws.spsx * tan(a->draws.r_ang);
	a->draws.nhorx = a->draws.intx;
	a->draws.nhory = a->draws.inty;
	norm_kostyl(a);
}

void	draw_rays_utils(t_all *all, int *i)
{
	draw_1(*i, all);
	draw_2(*i, all);
	if (all->draws.fhwhit)
		all->draws.hdistnc = phifagor(all->pl.p_x, all->pl.p_y,
				all->draws.hwhitx, all->draws.hwhity);
	else
		all->draws.hdistnc = INT_MAX;
	if (all->draws.vwallhit)
		all->draws.vdistnc = phifagor(all->pl.p_x, all->pl.p_y,
				all->draws.vwhitx, all->draws.vwhity);
	else
		all->draws.vdistnc = INT_MAX;
	if (all->draws.hdistnc < all->draws.vdistnc)
		all->rays[*i].wallhx = all->draws.hwhitx;
	else
		all->rays[*i].wallhx = all->draws.vwhitx;
}

void	draw_rays(t_all *all)
{
	int	i;

	all->draws.fhwhit = 0;
	all->draws.vwallhit = 0;
	all->draws.r_ang = (all->pl.d - 30) * (PI / 180);
	i = -1;
	while (++i < all->game.w)
	{
		draw_rays_utils(all, &i);
		if (all->draws.hdistnc < all->draws.vdistnc)
			all->rays[i].wallhy = all->draws.hwhity;
		else
			all->rays[i].wallhy = all->draws.vwhity;
		if (all->draws.hdistnc < all->draws.vdistnc)
			all->rays[i].distance = all->draws.hdistnc;
		else
			all->rays[i].distance = all->draws.vdistnc;
		all->rays[i].angle = all->draws.r_ang;
		all->rays[i].hitvert = (all->draws.vdistnc < all->draws.hdistnc);
		all->draws.r_ang += (60 * (PI / 180)) / all->game.w;
	}
}
