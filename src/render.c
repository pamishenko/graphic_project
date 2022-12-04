/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:21:26 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 11:26:38 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "../includes/cub3d.h"
#include "../includes/defines.h"
#include "../includes/mlx.h"

unsigned int	rgb_to_hex(int r, int g, int b)
{
	unsigned int	color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
	return (color);
}

void	rend_ha(t_all *a)
{
	a->rend.dist = a->rend.j - a->rend.top;
	a->wall.y = (a->rend.dist) * ((float)BLOCK_SIZE / a->rend.line);
	if (a->rend.i >= 0 && a->rend.i < a->game.w
		&& a->rend.j >= 0 && a->rend.j < a->game.h)
	{
		if (a->rays[a->rend.i].hitvert && a->rays[a->rend.i].right)
			a->mlx.img.addr[(int)a->rend.i + (int)a->rend.j * a->game.w]
				= (a->wall.tex[0][BLOCK_SIZE * a->wall.y + a->wall.x]);
		if (a->rays[a->rend.i].hitvert && a->rays[a->rend.i].left)
			a->mlx.img.addr[(int)a->rend.i + (int)a->rend.j * a->game.w]
				= a->wall.tex[1][BLOCK_SIZE * a->wall.y + a->wall.x];
		if (!a->rays[a->rend.i].hitvert && a->rays[a->rend.i].up)
			a->mlx.img.addr[(int)a->rend.i + (int)a->rend.j * a->game.w]
				= a->wall.tex[2][BLOCK_SIZE * a->wall.y + a->wall.x];
		if (!a->rays[a->rend.i].hitvert && a->rays[a->rend.i].down)
			a->mlx.img.addr[(int)a->rend.i + (int)a->rend.j * a->game.w]
				= a->wall.tex[3][BLOCK_SIZE * a->wall.y + a->wall.x];
	}
}

void	rend_hel(t_all *a)
{
	a->rend.raydist = a->rays[a->rend.i].distance
		* cosf(a->rays[a->rend.i].angle - (a->pl.d * PI / 180));
	a->rend.line = (BLOCK_SIZE / a->rend.raydist) * a->rend.distpj;
	a->rend.top = (a->game.h / 2) - (a->rend.line / 2) + a->pl.angle;
	a->rend.bottom = a->rend.top + a->rend.line;
	a->rend.j = 0;
	if (a->rays[a->rend.i].hitvert)
		a->wall.x = ((int)a->rays[a->rend.i].wallhy) % BLOCK_SIZE;
	else
	a->wall.x = ((int)a->rays[a->rend.i].wallhx) % BLOCK_SIZE;
	while (a->rend.j < a->rend.top)
	{
		a->rend.dist = a->rend.j - a->rend.top;
		a->wall.y = (int)((float)BLOCK_SIZE / a->rend.line * a->rend.dist)
			& (BLOCK_SIZE - 1);
		if (a->rend.i >= 0 && a->rend.i < a->game.w
			&& a->rend.j >= 0 && a->rend.j < a->game.h)
				a->mlx.img.addr[(int)a->rend.i + (int)a->rend.j * a->game.w]
				= rgb_to_hex(a->game.ceil.r, a->game.ceil.g, a->game.ceil.b);
		a->rend.j++;
	}
}

void	render_3d(t_all *a)
{
	a->rend.i = 0;
	a->rend.distpj = (a->game.w / 2) / (tan((30 * PI / 180)));
	while (a->rend.i < a->game.w)
	{
		rend_hel(a);
		while (a->rend.j < a->rend.bottom)
		{
			rend_ha(a);
			a->rend.j++;
		}
		while (a->rend.j < a->game.h)
		{
			a->rend.dist = a->rend.j - a->rend.top;
			a->wall.y = (int)((float)BLOCK_SIZE / a->rend.line * a->rend.dist)
				& (BLOCK_SIZE - 1);
			if (a->rend.i >= 0 && a->rend.i < a->game.w && a->rend.j >= 0
				&& a->rend.j < a->game.h)
				a->mlx.img.addr[(int)a->rend.i + (int)a->rend.j * a->game.w]
					= rgb_to_hex(a->game.fl.r, a->game.fl.g, a->game.fl.b);
			a->rend.j++;
		}
		a->rend.i++;
	}
}
