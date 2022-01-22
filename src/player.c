/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:54:29 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/22 18:55:21 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>

#include <cub3d.h>


int	is_player(t_all *all, char ch)
{
	if (ch == 'N')
	{
		all->plr->dir = M_PI;
		return (1);
	}
	else if (ch == 'S')
	{
		all->plr->dir = M_PI * 2;
		return (1);
	}
	else if (ch == 'E')
	{
		all->plr->dir = M_PI_2;
		return (1);
	}
	else if (ch == 'W')
	{
		all->plr->dir = M_PI_2 + M_PI;
		return (1);
	}
	return (0); 
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
			if (is_player(all, all->map[y][x]))
			{
				all->plr->x = x;
				all->plr->y = y;
				break;
			}
			x++;
		}
		y++;
	}
	all->plr->start = all->plr->dir - M_PI_4;
	all->plr->end = all->plr->dir + M_PI_4;

}