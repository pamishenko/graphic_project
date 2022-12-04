/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:27:14 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 13:27:01 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/cub3d.h"

void	key_init(t_all *all)
{
	all->key.back = 0;
	all->key.down = 0;
	all->key.exit = 0;
	all->key.left = 0;
	all->key.leftd = 0;
	all->key.right = 0;
	all->key.rightd = 0;
	all->key.straight = 0;
	all->key.up = 0;
}

float	norm_angle(float rayang)
{
	rayang = remainder(rayang, 2 * PI);
	if (rayang < 0)
		rayang += 2 * PI;
	else
		rayang += 0;
	return (rayang);
}

int	check_param(char *line)
{
	if (!ft_strncmp(line, "R ", 2) || !ft_strncmp(line, "NO ", 3))
		return (0);
	else if (!ft_strncmp(line, "EA ", 3))
		return (0);
	else if (!ft_strncmp(line, "WE ", 3))
		return (0);
	else if (!ft_strncmp(line, "SO ", 3))
		return (0);
	else if (!ft_strncmp(line, "F ", 2))
		return (0);
	else if (!ft_strncmp(line, "C ", 2))
		return (0);
	else if (line[0] == '\0' || line[0] == '1'
		|| line[0] == ' ')
		return (0);
	else
		return (exit_error(ENOEXEC));
	return (0);
}
