/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:58:45 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 14:20:54 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/defines.h"
#include "../includes/cub3d.h"

int	exit_error(int err)
{
	errno = err;
	perror(TEXT_RED"Error\n");
	write(0, TEXT_END_COLOR, 0);
	exit (err);
	return (err);
}

void	check_player_error(int i, int j, t_all *all)
{
	int	n;

	n = 1;
	j++;
	while (i < all->map.y_size)
	{
		if (n == 0)
			j = 0;
		if (n == 1)
			n = 0;
		while (all->map.mp[i][j])
		{
			if (all->map.mp[i][j] == 'N' || all->map.mp[i][j] == 'S'
					|| all->map.mp[i][j] == 'W' || all->map.mp[i][j] == 'E')
				exit_error(ENOEXEC);
			j++;
		}
		i++;
	}
}

void	err_map(int i, int j, t_all *a)
{
	if (a->map.mp[i][j] == '0')
	{
		if (i + 1 >= a->count_readed_str)
			exit_error(ENOEXEC);
		else if (a->map.mp[i][j + 1] == ' ' || a->map.mp[i][j + 1]
				== '\0' || a->map.mp[i + 1][j] == ' ' || !a->map.mp[i - 1][j]
				|| !a->map.mp[i - 1][j] || !a->map.mp[i + 1][j])
			exit_error(ENOEXEC);
	}
	else if (a->map.mp[i][j] == ' ' && (i + 1) < a->count_readed_str)
	{
		if (a->map.mp[i][j + 1] == '0' || a->map.mp[i + 1][j] == '0' ||
		a->map.mp[i][j + 1] == a->pl.sp || a->map.mp[i + 1][j] == a->pl.sp)
			exit_error(ENOEXEC);
	}
	else if (a->map.mp[i][j] == a->pl.sp)
	{
		check_player_error(i, j, a);
		if (i + 1 >= a->count_readed_str)
			exit_error(ENOEXEC);
		else if (a->map.mp[i][j + 1] == ' ' || a->map.mp[i][j + 1] == '\0' ||
				a->map.mp[i + 1][j] == ' ' || !a->map.mp[i - 1][j] ||
				!a->map.mp[i + 1][j])
			exit_error(ENOEXEC);
	}
}

void	check_map_error(t_all *a)
{
	int			i;
	int			j;
	static int	n = 0;

	i = -1;
	while (++i < a->count_readed_str)
	{
		j = -1;
		if (a->map.mp[i][0] == '\0')
			exit_error(ENOEXEC);
		while (a->map.mp[i][++j])
		{
			if (!a->pl.sp)
				exit_error(ENOEXEC);
			if (n == 0 && (a->map.mp[i][j] == '0'
				|| a->map.mp[i][j] == a->pl.sp))
				exit_error(ENOEXEC);
			n = 1;
			err_map(i, j, a);
			if (a->map.mp[i][j] != '0' && a->map.mp[i][j] != ' ' &&
					a->map.mp[i][j] != '1' && a->map.mp[i][j] != '2'
					&& a->map.mp[i][j] != a->pl.sp && a->map.mp[i][j] != '3')
				exit_error(ENOEXEC);
		}
	}
}
