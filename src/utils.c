/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:30:22 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/26 17:17:51 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>
#include <mlx.h>
 
int check_wall(t_all *all, int x, int y)
{
	if (all->map[(int)all->plr->curent_position.y + y][(int)all->plr->curent_position.x + x] == '1')
		return (1);
	else if (all->map[(int)all->plr->curent_position.y + y][(int)all->plr->curent_position.x + x] == '2')
		return (1);
	else if (all->map[(int)all->plr->curent_position.y + y][(int)all->plr->curent_position.x + x] == '3')
		return (1);
	else if (all->map[(int)all->plr->curent_position.y + y][(int)all->plr->curent_position.x + x] == '4')
		return (1);
	else if (all->map[(int)all->plr->curent_position.y + y][(int)all->plr->curent_position.x + x] == '5')
		return (1);
	return (0);
}