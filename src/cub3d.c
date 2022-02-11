/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:10:53 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/06 11:04:27by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>

void draw_rays_3d(t_all *all){
	// t_plr	ray = *all->plr; // задаем координаты луча равные координатам игрока

	// (void)ray;
	// while (all->mapa->map[all->mapa->size / ((int)(ray.py + ray.dpy)) /MAP_SIZE + (((int)(ray.px + ray.dpx)) /MAP_SIZE)]!= '1')
	// {
	// 	ray.dpx += cos(ray.dir);
	// 	ray.dpy += sin(ray.dir);
	// 	mlx_pixel_put(all->win->mlx, all->win->win, ray.px + ray.dpx, ray.py + ray.dpy, BLUE);
	// }
	(void)all;
}

void draw_rays_3d_2(t_all *all)
{
	int r, mx, my, mp, dof;
	float rx, ry, ra, xo, yo;
	ra = all->plr->dir;

	for (r = 0; r < 1; r++)
	{
		dof = 0;
		float a_tan = -1/tan(ra);
		if (ra > M_PI){
			ry = (((int)all->plr->py >> 6) << 6) - 0.0001;
			rx = (all->plr->py - ry) * a_tan + all->plr->px;
			yo = - 64;
			xo = -yo * a_tan;
		}
		if (ra < M_PI){
			ry = (((int)all->plr->py >> 6) << 6) + 64;
			rx = (all->plr->py - ry) * a_tan + all->plr->px;
			yo = 64;
			xo = -yo * a_tan;
		}
		if (ra == 0 || ra == M_PI){
			rx = all->plr->px;
			ry = all->plr->py;
			dof = MAP_SIZE;
		}
		while (dof < 64)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * all->mapa->x + mx;
			if (mp < all->mapa->x * all->mapa->y && all->mapa->map[mp] == '1'){
				dof = 64;
			}
			else {
				rx += xo;
				ry += yo;
				dof += 1;
			}
			mlx_pixel_put(all->win->mlx, all->win->win, all->plr->px + rx / MAP_SIZE,
				all->plr->py + ry / MAP_SIZE, GREEN);
			printf("rx = %f .  ry = %f\n", rx, ry);
		}
		
	}
}




int	main(int argc, char **argv){
	t_all *all;
	
	(void)argc;
	all = init_game(argv);
	set_player(all);
	draw_map_2d(all);
	draw_player_on_minimap(all);
	mlx_hook(all->win->win, 2, (1L << 0), &buttons, all);
	mlx_loop(all->win->mlx);
}
