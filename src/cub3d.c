/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:10:53 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/04 22:26:06 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>

int	ft_close(int keycode, t_all *all)
{
	(void)keycode;
	mlx_destroy_window(all->win->mlx, all->win->win);
	return (0);
}

int	main(int argc, char **argv){
	t_all *all;
	
	(void)argc;
	all = init_game(argv);
	set_player(all);
	draw_map_2d(all);
	draw_player_on_minimap(all);
	mlx_hook(all->win->win, 2, (1L << 0), &buttons, all);
	// mlx_hook(all->win->win, 2, 1L<<0, &ft_close, all);
	printf("map -> %s \n", all->mapa->map);
	mlx_loop(all->win->mlx);
}
