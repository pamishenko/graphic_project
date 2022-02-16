/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:14:17 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/16 18:14:36 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_wall
{
	int		color_count;
	char	*colors_symbol;
	int		*colors_code;
	int		size;
	int		*pixels;
}		t_wall;

typedef struct s_cub
{ 
	char	name;
	t_wall	*north_wall;
	t_wall	*south_wall;
	t_wall	*west_wall;
	t_wall	*east_wall;
}		t_cub;



t_wall *parse_wall(char *xpm_file)
{
	int		fd;
	char	*line;

	open(xpm_file, fd, O_RDONLY);
	while((ft_get_next_line(fd, &line)) > 0)
	{
		
	}
	close(fd);
}

t_cub *init_cub(void)
{
	t_cub *cub;

	cub = ft_calloc(sizeof(cub), 1);
	cub->north_wall = parse_wall("./img/wall/north.xpm");
	cub->south_wall = parse_wall("./img/wall/north.xpm");
	cub->west_wall = parse_wall("./img/wall/north.xpm");
	cub->east_wall = parse_wall("./img/wall/north.xpm");
}


void destroy_wall(t_wall *wall)
{
	
}

void destroy_cub(t_cub *cub)
{
	destroy_wall(cub->north_wall);
	destroy_wall(cub->south_wall);
	destroy_wall(cub->west_wall);
	destroy_wall(cub->east_wall);
	free(cub);
}