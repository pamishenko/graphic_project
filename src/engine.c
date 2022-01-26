/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:15:06 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/26 23:39:26 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>




float	get_len(t_position start_position, t_position wal_position)
{
	float result;

	result = sqrt((start_position.x - wal_position.x)*(start_position.x
				- wal_position.x) + (start_position.y - wal_position.y)
				* (start_position.y - wal_position.y));
			printf("%f\n", result);
	return (result);
}

void print_wall(t_all *all, float x, float c)
{
	for (int y = (WIDTH - (WIDTH / c)) / 2; y < ((WIDTH - (WIDTH / c)) / 2 + (WIDTH / c)); y++)
		mlx_pixel_put(all->win->mlx, all->win->win, HEIGHT - (int)x, y, 0x00FF0000 + (0xFF000000 - (0xFF000000<<(int)c/6)));
	
}

void	ft_cast_rays(t_all *all)
{
	t_plr	ray = *all->plr; // задаем координаты и направление луча равные координатам игрока
	ray.start = ray.dir - M_PI_4; // начало веера лучей
	ray.end = ray.dir + M_PI_4; // край веера лучей
	int i = 0;
  while (ray.start <= ray.end)
	{
		if (i == HEIGHT +1)
			i++;
		i++;
		ray.curent_position.x = all->plr->curent_position.x; // каждый раз возвращаемся в точку начала
		ray.curent_position.y = all->plr->curent_position.y;
		while (all->map[(int)(ray.curent_position.y)][(int)(ray.curent_position.x)] != '1')
		{
			ray.curent_position.x +=  (sin(ray.start) / MAP_SIZE);
			ray.curent_position.y +=  (cos(ray.start) / MAP_SIZE);
			// mlx_pixel_put(all->win->mlx, all->win->win, (int)(ray.curent_position.x * 4), (int)(ray.curent_position.y * 4), 0x00990099);
		}
		print_wall(all, i, get_len(all->plr->curent_position, ray.curent_position));
		ray.start += M_PI_2 / HEIGHT;
	}
}
