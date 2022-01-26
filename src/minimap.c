/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:51:17 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/26 23:18:55 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>
#include <mlx.h>

void	draw_mini_map(t_all *all)
{
	int	x;
	int	y;
	int	i;
	int j;
	
	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '1')
			{
				i = 0;
				while (++i <= 4)
				{
					j = 0;
					while (++j <= 4)
							mlx_pixel_put(all->win->mlx, all->win->win,
									j + (x * 4), i + (y * 4), 0x00FFFF00);
				}
			}
			x++;
		}
		y++;
	}
}