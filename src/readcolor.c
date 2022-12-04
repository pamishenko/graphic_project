/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readcolor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:02:57 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 13:09:06 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/libft.h"
#include "../includes/cub3d.h"

void	set_color(t_color *color, unsigned char *str)
{
	color->r = ft_atoi(ft_split((const unsigned char *)str, ',')[0]);
	color->g = ft_atoi(ft_split((const unsigned char *)str, ',')[1]);
	color->b = ft_atoi(ft_split((const unsigned char *)str, ',')[2]);
}

int	check_trim(char *s_r, char *s_g, char *s_b)
{
	int	i;

	i = -1;
	s_r = ft_strtrim(s_r, " \t");
	s_g = ft_strtrim(s_g, " \t");
	s_b = ft_strtrim(s_b, " \t");
	while (s_r[++i])
		if (s_r[i] == ' ' || s_r[i] == '\t')
			return (1);
	i = -1;
	while (s_g[++i])
		if (s_g[i] == ' ' || s_g[i] == '\t')
			return (1);
	i = 1;
	while (s_b[++i])
		if (s_b[i] == ' ' || s_b[i] == '\t')
			return (1);
	return (0);
}

int	read_color(char *str, int *count, t_color *color, char *s)
{
	*count += 1;
	str = ft_strtrim((const char *)str, s);
	if (!ft_split((const char *)str, ',')[0] || !ft_split((const char *)str,
			',')[1] || !ft_split((const char *)str, ',')[2]
			|| get_comma_count(str) != 2)
		return (exit_error(ENOEXEC));
	else if (ft_strisnum(ft_split((const char *)str, ',')[0]) ||
			ft_strisnum(ft_split((const char *)str, ',')[1])
			|| ft_strisnum(ft_split((const char *)str, ',')[2]))
		return (exit_error(ENOEXEC));
	else
	{
		if (ft_atoi(ft_split((const char *)str, ',')[0]) > 255
			|| ft_atoi(ft_split((const char *)str, ',')[1]) > 255
			|| ft_atoi(ft_split((const char *)str, ',')[2]) > 255)
			return (exit_error(ENOEXEC));
		else if (check_trim(ft_split((const char *)str, ',')[0],
			ft_split((const char *)str, ',')[2],
			ft_split((const char *)str, ',')[1]))
			return (exit_error(ENOEXEC));
		else
			set_color(color, str);
	}
	return (0);
}

int	read_textures(char *str, char *s2, t_all *all)
{
	int	fd;

	fd = -1;
	all->map_line_counter += 1;
	fd = open(ft_split((const char *)str, ' ')[1], O_RDONLY);
	if (fd == -1)
		return (exit_error(ENOEXEC));
	else
		ft_strlcpy(s2, ft_split((const char *)str, ' ')[1],
			ft_strlen(ft_split((const char *)str, ' ')[1]) + 1);
	return (0);
}
