/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawrays_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:14:26 by ttanja            #+#    #+#             */
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

void	continue_draw(t_all *a, int *i)
{
	if (a->rays[*i].up)
		a->draws.spsy *= -1;
	else
		a->draws.spsy *= 1;
	a->draws.spsx = a->draws.spsy / tan(a->draws.r_ang);
	a->draws.nhorx = a->draws.intx;
	a->draws.nhory = a->draws.inty;
	while (a->draws.nhorx >= 0 && a->draws.nhorx <= a->map.max * BLOCK_SIZE
		&& a->draws.nhory >= 0 && a->draws.nhory <= a->map.y_size * BLOCK_SIZE)
	{
		if (!(iswal(a->draws.nhory - a->draws.tchk, a->draws.nhorx, a)))
		{
			a->draws.fhwhit = 1;
			a->draws.hwhitx = a->draws.nhorx;
			a->draws.hwhity = a->draws.nhory;
			break ;
		}
		else
		{
			a->draws.nhorx += a->draws.spsx;
			a->draws.nhory += a->draws.spsy;
		}
	}
}

void	draw_1(int i, t_all *a)
{
	a->draws.fhwhit = 0;
	a->draws.vwallhit = 0;
	a->draws.r_ang = norm_angle(a->draws.r_ang);
	a->rays[i].down = ((a->draws.r_ang > 0) && (a->draws.r_ang < PI));
	a->rays[i].up = !a->rays[i].down;
	a->rays[i].right = ((a->draws.r_ang < (0.5 * PI))
			|| (a->draws.r_ang > 1.5 * PI));
	a->rays[i].left = !a->rays[i].right;
	if (a->rays[i].up)
		a->draws.tchk = 1;
	else
		a->draws.tchk = 0;
	a->draws.inty = floor((a->pl.p_y / BLOCK_SIZE)) * BLOCK_SIZE;
	if (a->rays[i].down)
		a->draws.inty += BLOCK_SIZE;
	a->draws.intx = a->pl.p_x - ((a->pl.p_y - a->draws.inty)
			/ tan(a->draws.r_ang));
	a->draws.spsy = BLOCK_SIZE;
	continue_draw(a, &i);
}
