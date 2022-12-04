/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:40:32 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 14:43:08 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/mlx.h"
#include "../includes/cub3d.h"

int	exit_game(int key, t_all *all)
{
	exit(0);
}

int	key_unpress(int key, t_all *all)
{
	if (key == 53)
		all->key.exit = -1;
	if (key == 124)
		all->key.rightd = -1;
	if (key == 123)
		all->key.leftd = -1;
	if (key == 0)
		all->key.left = -1;
	if (key == 2)
		all->key.right = -1;
	if (key == 1)
		all->key.back = -1;
	if (key == 13)
		all->key.straight = -1;
	if (key == 126)
		all->key.up = -1;
	if (key == 125)
		all->key.down = -1;
	return (0);
}

int	key_press(int key, t_all *all)
{
	if (key == 53)
		all->key.exit = 1;
	if (key == 124)
		all->key.rightd = 1;
	if (key == 123)
		all->key.leftd = 1;
	if (key == 0)
		all->key.left = 1;
	if (key == 2)
		all->key.right = 1;
	if (key == 1)
		all->key.back = 1;
	if (key == 13)
		all->key.straight = 1;
	if (key == 126)
		all->key.up = 1;
	if (key == 125)
		all->key.down = 1;
	return (0);
}
