/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:05:12 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 12:26:52 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/cub3d.h"
#include "../includes/defines.h"
#include "../includes/mlx.h"

void	update2(t_all *all)
{
	if (all->key.leftd == 1)
		all->pl.d -= 2;
	if (all->key.rightd == 1)
		all->pl.d += 2;
	mlx_destroy_image(all->mlx.mlx, all->mlx.img.img);
	mlx_clear_window(all->mlx.mlx, all->mlx.win);
	all->mlx.img.img = mlx_new_image(all->mlx.mlx, all->game.w, all->game.h);
	all->mlx.img.addr = (char *)mlx_get_data_addr(all->mlx.img.img,
			&all->mlx.img.bpp, &all->mlx.img.line_len, &all->mlx.img.end);
	all->mlx.x = 0;
	all->mlx.y = 0;
	draw_rays(all);
	render_3d(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img.img, 0, 0);
}

void	norma_kostyl(t_all *a)
{
	if (a->key.exit == 1)
	{
		mlx_destroy_window(a->mlx.mlx, a->mlx.win);
		exit(0);
	}
	if (a->key.left == 1)
	{
		if (iswal(((a->pl.p_y - sin((a->pl.d + 90) * (PI / 180)) * 32)),
				((a->pl.p_x - cos((a->pl.d + 90) * (PI / 180)) * 32)), a))
		{
			a->pl.p_x -= cos((a->pl.d + 90) * (PI / 180)) * a->pl.s;
			a->pl.p_y -= sin((a->pl.d + 90) * (PI / 180)) * a->pl.s;
		}
	}
	if (a->key.right == 1)
	{
		if (iswal(((a->pl.p_y + sin((a->pl.d + 90) * (PI / 180)) * 32)),
				((a->pl.p_x + cos((a->pl.d + 90) * (PI / 180)) * 32)), a))
		{
			a->pl.p_x += cos((a->pl.d + 90) * (PI / 180)) * a->pl.s;
			a->pl.p_y += sin((a->pl.d + 90) * (PI / 180)) * a->pl.s;
		}
	}
}

int	update(t_all *a)
{
	norma_kostyl(a);
	if (a->key.back == 1)
	{
		if (iswal(((a->pl.p_y - sin((a->pl.d) * (PI / 180)) * 32)),
				((a->pl.p_x - cos((a->pl.d) * (PI / 180)) * 32)), a))
		{
			a->pl.p_x = a->pl.p_x - cos((a->pl.d) * (PI / 180)) * a->pl.s;
			a->pl.p_y = a->pl.p_y - sin((a->pl.d) * (PI / 180)) * a->pl.s;
		}
	}
	if (a->key.straight == 1)
	{
		if (iswal(((a->pl.p_y + sin((a->pl.d) * (PI / 180)) * 32)),
				((a->pl.p_x + cos((a->pl.d) * (PI / 180)) * 32)), a))
		{
			a->pl.p_x = a->pl.p_x + cos((a->pl.d) * (PI / 180)) * a->pl.s;
			a->pl.p_y = a->pl.p_y + sin((a->pl.d) * (PI / 180)) * a->pl.s;
		}
	}
	update2(a);
	return (0);
}
