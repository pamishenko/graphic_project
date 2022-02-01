/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:11:41 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/01 23:55:32 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>

#include <cub3d.h>

int	buttons(int key, t_all *all)
{
	if (key == A)
		all->plr->position.x--;
	if (key == D)
		all->plr->position.x++;
	if (key == W)
		all->plr->position.y--;
	if (key == S)
		all->plr->position.y++;
	redisplay(all);
	return (0);
}