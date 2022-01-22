/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:10:53 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/22 19:08:05 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>

#include <cub3d.h>

void print_wall(t_all *all, int vec, int x)
{
	for (int i = 1; i < 1000 / vec; i++)
			mlx_pixel_put(all->win->mlx, all->win->win, x+100, i+200, 0x00FFFFAC * vec * i/ 100);

}

void	ft_cast_rays(t_all *all)
{
	t_plr	ray = *all->plr; // задаем координаты и направление луча равные координатам игрока
	int i, u;
	ray.start = ray.dir - M_PI_4; // начало веера лучей
	ray.end = ray.dir + M_PI_4; // край веера лучей
		u = 1;
  while (ray.start <= ray.end)
	{
		i = 0;
		ray.x = all->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = all->plr->y;
		u++;
		while (all->map[(int)(ray.y)][(int)(ray.x)] != '1')
		{
			i++;
			ray.x += sin(ray.start)/SCALE;
			ray.y += cos(ray.start)/SCALE;
					mlx_pixel_put(all->win->mlx, all->win->win, ray.x * SCALE, ray.y * SCALE, 0x00990099);
		}
		ray.start += M_PI_2 / 1280;
		print_wall(all, i, u/2);
	}
}



void	draw_map(t_all *all)
{
	int		x;
	int		y =	0;
	
		while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '1')
				for (int i = 1; i <= SCALE; i++)
					for (int j = 1; j <= SCALE; j++)
						mlx_pixel_put(all->win->mlx, all->win->win, j + (x * SCALE), i + (y * SCALE), 0x00FFFF00);
			x++;
		}
		y++;
	}
}

int check_wall(t_all *all, int x, int y)
{
	if (all->map[(int)all->plr->y + y][(int)all->plr->x + x] == '1')
		return (1);
	else if (all->map[(int)all->plr->y + y][(int)all->plr->x + x] == '2')
		return (1);
	else if (all->map[(int)all->plr->y + y][(int)all->plr->x + x] == '3')
		return (1);
	else if (all->map[(int)all->plr->y + y][(int)all->plr->x + x] == '4')
		return (1);
	else if (all->map[(int)all->plr->y + y][(int)all->plr->x + x] == '5')
		return (1);
	return (0);
}

int	move_minimap(int key, t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	draw_map(all);
	if(key == 13 && !check_wall(all, 0, -1))
	{
		all->plr->y += cos(all->plr->dir) * 0.5;
		all->plr->x += sin(all->plr->dir) * 0.5;
	}
	else if(key == 1 && !check_wall(all, 0, 1))
	{
		all->plr->y -= cos(all->plr->dir) * 0.5;
		all->plr->x -= sin(all->plr->dir) * 0.5;
	}
	else if(key == 0 && !check_wall(all, -1, 0))
		all->plr->dir += 0.05;
	else if(key == 2 && !check_wall(all, 1, 0))
		all->plr->dir -= 0.05;
	else if (key == 53)
	{
		mlx_destroy_window(all->win->mlx, all->win->win);
		exit (0);
	}
	ft_cast_rays(all);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	all;
	
	(void)argc;
	all.plr = calloc(sizeof(t_plr), 1);
	all.win = calloc(sizeof(t_win), 1);
	all.win->win = calloc(sizeof(void), 1);
	all.win->mlx = calloc(sizeof(void), 1);
	all.map = parse_map(argv);
	set_player(&all);
	all.win->mlx = mlx_init();
	all.win->win = mlx_new_window(all.win->mlx, 1280, 720, "my Cub3D");	

	draw_map(&all);
	ft_cast_rays(&all);
	mlx_hook(all.win->win, 2, (1L << 0), &move_minimap, &all);
	mlx_loop(all.win->mlx);	
}