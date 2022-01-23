/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:10:53 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/23 01:17:09 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>

#include <cub3d.h>

t_resolution resolution;

void print_wall(t_all *all, int vec, int x)
{
	// void	*img;
	// char	*relative_path = "./img/512x512/Brick/Brick_14-512x512.xpm";
	// int		img_width = 1;
	// int		img_height = 1;
	// (void)vec;
	// (void)x;
	
	for (int i = 1; i < 1280; i++)
			mlx_pixel_put(all->win->mlx, all->win->win, x, i+200, 0x00FFFFAC * vec/16);

	// img = mlx_xpm_file_to_image(all->win->mlx, relative_path, &img_width, &img_height);
	// mlx_put_image_to_window(all->win->mlx, all->win->win, img, 1, 1);
}

int bit_wal(int x, int y, int i, int j)
{
	if (i < x && (i + 0.1) >= x)
		return (1);
	else if (i > x && (i + 0.1) >= x)
		return (1);
	else if (i < x && (i + 0.1) >= x)
		return (1);
	else if (i < x && (i + 0.1) >= x)
		return (1);
	return (0);
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
			ray.x += sin(ray.start) / SCALE;
			ray.y += cos(ray.start) / SCALE;
			// printf("x = %f   y = %f\n", ray.x, ray.y);
			mlx_pixel_put(all->win->mlx, all->win->win, (int)(ray.x * SCALE), (int)(ray.y * SCALE), 0x00990099);
		}
		ray.start += M_PI_2 / resolution.height;
		print_wall(all, i, u);
	}
}

void	draw_flor(t_all *all)
{
	for (int i = 1; i < resolution.height; i++)
		for (int j = resolution.width / 2; j < resolution.width; j++)
			mlx_pixel_put(all->win->mlx, all->win->win, i , j , 0x00FFFF00<<1*2);

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
	draw_mini_map(all);
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
	resolution.width = 720;
	resolution.height = 1280;
	
	(void)argc;
	all.plr = calloc(sizeof(t_plr), 1);
	all.win = calloc(sizeof(t_win), 1);
	all.win->win = calloc(sizeof(void), 1);
	all.win->mlx = calloc(sizeof(void), 1);
	all.map = parse_map(argv);
	set_player(&all);
	all.win->mlx = mlx_init();
	all.win->win = mlx_new_window(all.win->mlx, resolution.height, resolution.width, "my Cub3D");	

	draw_mini_map(&all);
	ft_cast_rays(&all);
	mlx_hook(all.win->win, 2, (1L << 0), &move_minimap, &all);
	mlx_loop(all.win->mlx);	
}