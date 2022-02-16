/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:10:53 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/06 11:04:27by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>

void	floor_and_ceiling(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < WIDTH / 2)
	{
		x = 0;
		while (x++ < HEIGHT)
		{

			my_mlx_pixel_put(all->data, x, WIDTH / 2 - y, 0x0001E90F);
			my_mlx_pixel_put(all->data, x, WIDTH / 2 + y, 0x00D2691E);
		}
	}
}

int get_side_of_the_world(int x, int y, int block_size, t_all *all)
{
	x %= (block_size);
	y %= (block_size);
	if ((x >= 1 || x <= block_size) && y % block_size > block_size / 3 && all->plr->dir > M_PI)
		return (RED);
	if ((x >= 0 || x <= block_size - 1) && y % block_size < block_size / 3 && all->plr->dir < M_PI)
		return (YELLOW);	
	if (x % block_size < block_size / 3 && (y >= 0 || y <= block_size - 1))
		return (BLACK);
	if (x % block_size > block_size / 3 && (y >= 1 || y <= block_size))
		return (GREEN);
	return (0);
}

// int	main(int argc, char **argv){
// 	t_all *all;
	
// 	(void)argc;
// 	all = init_game(argv);
// 	set_player(all);
// 	redisplay(all);
// 	// mlx_put_image_to_window(all->win->mlx, all->win->win, all->data)
// 	mlx_hook(all->win->win, 2, (1L << 0), &buttons, all);
// 	mlx_loop(all->win->mlx);
// }


int	main(int argc, char **argv)
{
	t_all *all;

	(void)argc;
	all = ft_calloc(sizeof(t_all), 1);
	all->win = ft_calloc(sizeof(t_win), 1); 
		all->plr = ft_calloc(sizeof(t_plr), 1);
	all->win->mlx = ft_calloc(sizeof(void), 1);	
	all->win->win = ft_calloc(sizeof(void), 1);
	all->data = ft_calloc(sizeof(t_data), 1);
	all->win->mlx = mlx_init();
	all->win->win = mlx_new_window(all->win->mlx, HEIGHT, WIDTH, "CUB3D");
	all->data->img = mlx_new_image(all->win->mlx, HEIGHT, WIDTH);
	all->data->addr = mlx_get_data_addr(all->data->img, &all->data->bits_per_pixel, &all->data->line_length,
								&all->data->endian);
		all->mapa = ft_calloc(sizeof(t_map), 1);
	parser_map(argv, all->mapa);
	set_player(all);
	floor_and_ceiling(all);
	draw_3d(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->data->img, 0, 0);
	mlx_hook(all->win->win, 2, (1L << 0), &buttons, all);
	mlx_loop(all->win->mlx);
}