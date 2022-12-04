/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:38:16 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 11:11:07 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/cub3d.h"
#include "../includes/defines.h"

void	set_texture(t_all *a)
{
	void	*img;
	int		tmp[5];

	a->mlx.mlx = mlx_init();
	a->mlx.win = mlx_new_window(a->mlx.mlx, a->game.w, a->game.h, "cub3D");
	a->mlx.img.img = mlx_new_image(a->mlx.mlx, a->game.w, a->game.h);
	a->mlx.img.addr = (int *)mlx_get_data_addr(a->mlx.img.img,
			&a->mlx.img.bpp, &a->mlx.img.line_len, &a->mlx.img.end);
	img = mlx_xpm_file_to_image(a->mlx.mlx, a->tex.tx_s, &tmp[0], &tmp[1]);
	a->wall.tex[0] = (int *)mlx_get_data_addr(img,
			&tmp[2], &tmp[3], &tmp[4]);
	img = mlx_xpm_file_to_image(a->mlx.mlx, a->tex.tx_e, &tmp[0], &tmp[1]);
	a->wall.tex[1] = (int *)mlx_get_data_addr(img,
			&tmp[2], &tmp[3], &tmp[4]);
	img = mlx_xpm_file_to_image(a->mlx.mlx, a->tex.tx_n, &tmp[0], &tmp[1]);
	a->wall.tex[2] = (int *)mlx_get_data_addr(img,
			&tmp[2], &tmp[3], &tmp[4]);
	img = mlx_xpm_file_to_image(a->mlx.mlx, a->tex.tx_w, &tmp[0], &tmp[1]);
	a->wall.tex[3] = (int *)mlx_get_data_addr(img,
			&tmp[2], &tmp[3], &tmp[4]);
}

int	iswal(float y, float x, t_all *all)
{
	if (x >= 0 && x < all->map.max * BLOCK_SIZE && y >= 0
		&& y < all->map.y_size * BLOCK_SIZE)
	{
		if (all->map.mp[(int)y / BLOCK_SIZE][(int)x / BLOCK_SIZE] != '1')
			return (1);
	}
	return (0);
}
