/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readconfig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:24:00 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 13:08:02 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/cub3d.h"
#include "../includes/libft.h"

int	ft_read_line_spec(char *line, t_all *all)
{
	if (!ft_strncmp(line, "R ", 2))
		if (set_win_size(line, &all->map_line_counter, all))
			return (1);
	if (!ft_strncmp(line, "NO ", 3))
		if (read_textures(line, all->tex.tx_n, all))
			return (1);
	if (!ft_strncmp(line, "EA ", 3))
		if (read_textures(line, all->tex.tx_e, all))
			return (1);
	if (!ft_strncmp(line, "WE ", 3))
		if (read_textures(line, all->tex.tx_w, all))
			return (1);
	if (!ft_strncmp(line, "SO ", 3))
		if (read_textures(line, all->tex.tx_s, all))
			return (1);
	if (!ft_strncmp(line, "C ", 2))
		if (read_color(line, &all->map_line_counter, &all->game.ceil, "C "))
			return (1);
	if (!ft_strncmp(line, "F ", 2))
		if (read_color(line, &all->map_line_counter, &all->game.fl, "F "))
			return (1);
	return (check_param(line));
}

void	continue_read_spec(t_all *all, char **line)
{
	ft_strlcpy(all->map.mp[all->map.y_size], *line, ft_strlen(*line) + 1);
	all->map.y_size++;
	all->count_readed_str++;
	all->map_line_counter = -1;
}

int	read_specification(int fd, t_all *all)
{
	char	*line;

	while (ft_get_next_line(fd, &line))
	{
		if (ft_read_line_spec(line, all))
			return (1);
		if ((all->map_line_counter == 7 || all->map_line_counter == -1)
			&& (line[0] == ' ' || line[0] == '1'))
		{
			all->map_line_counter = -1;
			ft_strlcpy(all->map.mp[all->map.y_size], line, ft_strlen(line) + 1);
			all->map.y_size++;
			all->count_readed_str++;
		}
		else if (all->map_line_counter == -1 && line[0] == '\0')
			ft_strlcpy(all->map.mp[all->map.y_size++], "error", 5);
		free(line);
	}
	if ((line[0] == ' ' || line[0] == '1'))
		continue_read_spec(all, &line);
	free(line);
	return (0);
}

int	read_file_map(char *str, t_all *all)
{
	int	fd;

	all->count_readed_str = 0;
	all->map_line_counter = 0;
	all->map.y_size = 0;
	fd = open(str, O_RDONLY);
	if (read_specification(fd, all))
		return (exit_error(EILSEQ));
	set_max_map_line(all);
	if (all->map_line_counter != -1)
		return (exit_error(EILSEQ));
	return (0);
}
