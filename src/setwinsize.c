/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setwinsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:59:02 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 10:55:59 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"

void	parse_winsize(char *str, t_all *all)
{
	if ((ft_atoi(ft_split((const char *)str, ' ')[1]) > 1920
		&& ft_atoi(ft_split((const char *)str, ' ')[2]) > 1080)
		|| (ft_atoi(ft_split((const char *)str, ' ')[1]) < 0
		&& ft_atoi(ft_split((const char *)str, ' ')[2]) < 0))
	{
		all->game.w = 1920;
		all->game.h = 1080;
	}
	else if (ft_atoi(ft_split((const char *)str, ' ')[1]) > 1920
			|| ft_atoi(ft_split((const char *)str, ' ')[1]) < 0)
	{
		all->game.w = 1920;
		all->game.h = ft_atoi(ft_split((const char *)str, ' ')[2]);
	}
	else if (ft_atoi(ft_split((const char *)str, ' ')[2]) > 1080
			|| ft_atoi(ft_split((const char *)str, ' ')[2]) < 0)
	{
		all->game.w = ft_atoi(ft_split((const char *)str, ' ')[1]);
		all->game.h = 1080;
	}
	else
	{
		all->game.w = ft_atoi(ft_split((const char *)str, ' ')[1]);
		all->game.h = ft_atoi(ft_split((const char *)str, ' ')[2]);
	}
}

int	set_win_size(char *str, int *count, t_all *all)
{
	*count += 1;
	if (!(ft_split((const char *)str, ' ')[1]) || !(ft_split((const char *)str,
					' ')[2]) || ft_split((const char *)str, ' ')[3])
		return (exit_error(EILSEQ));
	else
	{
		if (ft_strisnum(ft_split((const char *)str, ' ')[1])
			|| ft_strisnum(ft_split((const char *)str, ' ')[2]))
			return (exit_error(EILSEQ));
		else
			parse_winsize(str, all);
	}
	return (0);
}
