/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:12:11 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/26 17:12:21 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>
#include <mlx.h>

t_all *init_game(char **argv)
{
	t_all	*all;

	if (check_map(argv))
		return(NULL);
	all = ft_calloc(sizeof(t_all), 1);
	all->plr = ft_calloc(sizeof(t_plr), 1);
	all->win = ft_calloc(sizeof(t_win), 1);
	all->win->win = ft_calloc(sizeof(void), 1);
	all->win->mlx = ft_calloc(sizeof(void), 1);
	all->map = parse_map(argv);
	set_player(all);
	all->win->mlx = mlx_init();
	all->win->win = mlx_new_window(all->win->mlx, HEIGHT, WIDTH, "my Cub3D");	
	return (all);
}

int	destroy_game(t_all *all, int exit_code)
{
	free(all->plr);
	free(all->win->win);
	free(all->win->mlx);
	return (exit_code);
}