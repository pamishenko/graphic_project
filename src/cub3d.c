/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:10:53 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/02 00:09:46 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>

int	main(int argc, char **argv){
	t_all *all;
	
	(void)argc;
	all = init_game(argv);
	all->mapa = parser_map(argv);
	set_player(all);
	draw_map_2d(all);
	draw_player_on_minimap(all);
	mlx_hook(all->win->win, 2, (1L << 0), &buttons, all);
	mlx_loop(all->win->mlx);
}
