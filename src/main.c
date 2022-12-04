/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:38:09 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 14:42:45 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "../includes/cub3d.h"
#include "../includes/mlx.h"

int	engine(t_all *all)
{
	mlx_hook(all->mlx.win, 17, 0L, exit_game, all);
	mlx_hook(all->mlx.win, 2, 1L << 0, exit_game, all);
	mlx_hook(all->mlx.win, 2, 0, key_press, all);
	mlx_hook(all->mlx.win, 3, 0, key_unpress, all);
	update(all);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	all;

	errno = 0;
	if (argc != 2)
		return (exit_error(EINVAL));
	if (read_file_map(argv[1], &all))
		return (errno);
	search_player(&all);
	set_texture(&all);
	check_map_error(&all);
	key_init(&all);
	mlx_loop_hook(all.mlx.mlx, engine, &all);
	mlx_loop(all.mlx.mlx);
	return (0);
}
