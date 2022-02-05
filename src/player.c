/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:54:29 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/05 13:04:33 by ttanja           ###   ########.fr       */
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

int	set_player(t_all *all)
{
	int	i;
	int	result;

	i = 0;
	result = 21;
	// В этом месте нужно сделать чекер на то что на карте есть игрок и он один
	all->plr->realAngle = 0;
	all->plr->speed = 1;
	all->plr->rotSpeed = 5;
	while (i < all->mapa->x * all->mapa->y && !(result = is_player(all, all->mapa->map[i])))
		i++;
	all->plr->start = all->plr->dir - M_PI_4;
	all->plr->end = all->plr->dir + M_PI_4;

	if (result)
	{
		all->plr->px = (i % (all->mapa->x) * BLOCK_SIZE + BLOCK_SIZE  / 2  + PLAYER_SIZE / 2);
		all->plr->py = (i / (all->mapa->x) * BLOCK_SIZE + BLOCK_SIZE  / 2  + PLAYER_SIZE / 2);
		result = 0;
	}
	else
		result = 21;
	return (result);
}
