// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   3dsage.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/02/13 20:54:37 by ttanja            #+#    #+#             */
// /*   Updated: 2022/02/13 21:41:13by ttanja           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdio.h>

// #include <libft.h>
// #include <math.h>
// #include <cub3d.h>
// #include <mlx.h>


// #define mapX 8;
// #define mapY 8;
// #define mapS 64;

// 	void *mlx;
// 	void *win;
// 	// void *img;

// int map[] =
// {
// 	1,1,1,1,1,1,1,1,
// 	1,0,0,0,0,0,0,1,
// 	1,0,0,0,1,1,0,1,
// 	1,0,0,0,1,0,0,1,
// 	1,0,0,1,0,0,0,1,
// 	1,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,0,1,
// 	1,1,1,1,1,1,1,1,
// };

// void draw_square(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy, int color)
// {
// 	int	x;
// 	int y;
	
// 	y = ay - 1;
// 	while (++y <= cy)
// 	{
// 		x = ax - 1;
// 		while (++x <= cx)
// 		mlx_pixel_put(mlx, win, x, y, color);
// 	}
// 	x += ax + ay + bx + by + cx + cy + dx + dy;
// }

// void draw_point(int color, int point_size, int x, int y)
// {
// 	int i;
// 	int j;

// 	j = 0 - point_size % 2;
// 	while (++j <= point_size)
// 	{
// 		i = 0 - point_size % 2;
// 		while (++i <= point_size)
// 		{
// 			mlx_pixel_put(mlx, win, x + i, y + j, color);
// 		}
// 	}
// }

// void	draw_direction(float px, float py, float dpx, float dpy, int width, int color)
// {
// 	int i;
// 	int j;

// 	j = py - 1;
// 	while (++j < (int)dpy)
// 	{
// 		i = px - 1;
// 		while (++i < (int)dpx)
// 			mlx_pixel_put(mlx, win, dpx - i, dpy - j, color);
// 	}
// 	width = 1;
// }

// void	draw_map2d(void)
// {
// 	int x, y, xo, yo, color;
// 	int map_x = mapX;
// 	int map_y = mapY; 
// 	int	map_s = mapS;

// 	for (y = 0; y < map_y; y++)
// 	{
// 		for (x = 0; x < map_x; x++)
// 		{
// 			if (map[y * map_x + x] == 1)
// 				color = WHITE;
// 			else 
// 				color = BLACK;
// 			xo = x * map_s; yo = y * map_s;
// 			draw_square(0+xo+1, 0+yo+1,
// 						0+xo+1, map_s+yo-1,
// 						map_s+xo-1, map_s+yo-1,
// 						map_s+xo-1, 0+yo+1,
// 						color);
// 		}	
// 	}
// }


// float	deg_to_rad(int a)
// {
// 	return (a * M_PI / 180.0);
// }

// int fix_ang(int a)
// {
// 	if (a > 359)
// 		a -= 360;
// 	if (a < 0)
// 		a += 360;
// 	return (a);
// }

// float px = 222.0, py = 222.0, dpx = 0.0, dpy = 0.0 ,pa = M_PI_2;

// void draw_player_2d(void)
// {
// 		draw_point(RED, 8, px, py);
// 		//  draw_direction(px, py, dpx * 20, dpy * 20, 4, YELLOW);
// }

// void ft_redisplay(void)
// {
// 	// draw_map2d();
// 	draw_player_2d();
// }

// int button(int key)
// {
// 	if (key == A)
// 	{
// 		pa += 5;
// 		pa = fix_ang(pa);
// 		dpx = cos(deg_to_rad(pa));
// 		dpy = -sin(deg_to_rad(pa));
// 	}
// 		if (key == D)
// 	{
// 		pa -= 5;
// 		pa = fix_ang(pa);
// 		dpx = cos(deg_to_rad(pa));
// 		dpy = -sin(deg_to_rad(pa));
// 	}
// 		if (key == W)
// 	{
// 		px += dpx * 5;
// 		py += dpy * 5;
// 	}
// 		if (key == S)
// 	{
// 		px -= dpx * 5;
// 		py -= dpy * 5;
// 	}
// 	// printf("px = %f py = %f\n", px, py);
// 	ft_redisplay();
// 	return (0);
// }


// // int	main(void)
// // {

// // 	mlx = mlx_init();
// // 	win = mlx_new_window(mlx, HEIGHT, WIDTH, "test");	
// // 	draw_map2d();
// // 	draw_player_2d();
// // 	mlx_hook(win, 2, (1L << 0), &button, NULL);
// // 	mlx_loop(mlx);
// // 	return (0);	
// // }