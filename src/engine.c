/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:15:06 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/26 19:44:21 by ttanja           ###   ########.fr       */
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
	return (sqrt((start_position.x - wal_position.x)*(start_position.x
				- wal_position.x) + (start_position.y - wal_position.y)
				* (start_position.y - wal_position.y)));
}

void	ft_cast_rays(t_all *all)
{
	t_plr	ray = *all->plr; // задаем координаты и направление луча равные координатам игрока
	ray.start = ray.dir - M_PI_4; // начало веера лучей
	ray.end = ray.dir + M_PI_4; // край веера лучей
	int count;
  while (ray.start <= ray.end)
	{
		ray.curent_position.x = all->plr->curent_position.x; // каждый раз возвращаемся в точку начала
		ray.curent_position.y = all->plr->curent_position.y;
		count = 0;
		while (all->map[(int)(ray.curent_position.y)][(int)(ray.curent_position.x)] != '1')
		{
			ray.curent_position.x +=  (sin(ray.start) / MAP_SIZE);
			ray.curent_position.y +=  (cos(ray.start) / MAP_SIZE);
			mlx_pixel_put(all->win->mlx, all->win->win, (int)(ray.curent_position.x * MAP_SIZE), (int)(ray.curent_position.y * MAP_SIZE), 0x00990099);
			count++;
		}
		printf("%f\n",get_len(all->plr->curent_position, ray.curent_position));
		ray.start += M_PI_2 / HEIGHT;
	}
}
