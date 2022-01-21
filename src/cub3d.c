/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:10:53 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/21 21:19:34 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>

#include <cub3d.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_cast_ray(t_all *all)
{
	t_plr	ray = *all->plr; // задаем координаты луча равные координатам игрока

	while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
	{
		ray.x += cos(ray.dir);
		ray.y += sin(ray.dir);
		mlx_pixel_put(all->win->mlx, all->win, ray.x, ray.y, 0x990099);
	}
}

void	set_player(t_all *all)
{
	int x;
	int y = 0;
	while(all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'P')
			{
				all->plr->x = x;
				all->plr->y = y;
			}
			x++;
		}
		y++;
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
				for (int i = 1; i <= 10; i++)
					for (int j = 1; j <= 10; j++)
						mlx_pixel_put(all->win->mlx, all->win->win, j + (x * 10), i + (y * 10), 0x00FFFF00);
			x++;
		}
		y++;
	}
}



void	draw_player(t_all *all)
{
	int		x;
	int		y =	0;
	
		while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '1')
				for (int i = 1; i <= 10; i++)
					for (int j = 1; j <= 10; j++)
						mlx_pixel_put(all->win->mlx, all->win->win, j + (all->plr->x * 10), i + (all->plr->y * 10), 0x0000FFFA);
			x++;
		}
		y++;
	}
}

#include <stdio.h>
int	move_minimap(int key, t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	draw_map(all);
	if(key == 13)
		all->plr->y--;
	else if(key == 1)
		all->plr->y++;
	else if(key == 0)
		all->plr->x--;
	else if(key == 2)
		all->plr->x++;
	draw_player(all);
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
	mlx_hook(all.win->win, 2, (1L << 0), &move_minimap, &all);
	mlx_loop(all.win->mlx);	
}