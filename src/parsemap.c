/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:12:07 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/04 22:54:00 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <cub3d.h>
#include <stdio.h>

void	set_size_map(char **argv, t_map *map)
{
	int		fd;
	char	*line = NULL;

	map->x = 0;
	map->y = 0;
	fd = open(argv[1], O_RDONLY);
	while (ft_get_next_line(fd, &line) > 0)
	{
		if (map->x < (int)ft_strlen(line))
			map->x = ft_strlen(line);
		free(line);
		map->y += 1;
	}
	if (line)
		free(line);
	close(fd);
}

void set_map(int i, int j, char *line, t_map *mapa)
{
	while (line[i])
	{
		if (!ft_strchr("10WNSE", line[i]))
			break;
		if (line[i] == '1')
			mapa->map[j + i] = '1';
		else if ((line[i] == 'W') || (line[i] == 'S')
				|| (line[i] == 'N') || (line[i] == 'E'))
			mapa->map[j + i] = line[i];
		else
			mapa->map[j + i] = '0';
		i++;
	}
	while (i < mapa->x)
		mapa->map[j + i++] = '0';
	mapa->map[j + i++] = '\0';
	free(line);
}

t_map *parser_map(char **argv, t_map	*mapa)
{
	int		fd;
	char	*line;
	int i;
	int	j;

	j = 0;
	set_size_map(argv, mapa);
	mapa->map = ft_calloc(sizeof(char), ((mapa->x * mapa->y) * 2));
	fd = open(argv[1], O_RDONLY);
	while ((ft_get_next_line(fd, &line)) > 0)
	{
		i = 0;
		set_map(i, j, line, mapa);
		j += mapa->x;
	}
	i = 0;
	set_map(i, j, line, mapa);
	close(fd);
	return (mapa);
}