/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:06:35 by ttanja            #+#    #+#             */
/*   Updated: 2022/01/26 23:30:05 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

#define RESET_TXT   "\033[0m"
#define RED_TXT     "\033[1;31m"
#define YELLOW_TXT  "\033[1;33m"
#define WHITE_TXT   "\033[1;37m"

#define HEIGHT 640
#define WIDTH 480

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

#define MAP_SIZE 128 // условный размер каждого квадратика в карте

#include <libft.h>

typedef struct s_resolution
{
	int	width;
	int	height;
	int	fps;
} t_resolution;


typedef struct	s_win //структура для окна
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr; 
	int				line_l;
	int				bpp;
	int				en;
	t_resolution	resolution;
}	t_win;

typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				  t_point;

typedef struct s_position
{
	float x;
	float y;
} t_position;


typedef struct	s_plr //структура для игрока и луча
{
	t_position	curent_position;
	t_position	delta_position;
	float		dir;
	float		start;
	float		end;
	int			realAngle;
	int			fakeAngle;
	float			speed;
	float			rotSpeed;
}				  t_plr;

typedef struct s_block
{
	int	x;
	int	y;
	char *n_wall;
	char *s_wall;
	char *e_wall;
	char *w_wall;
} t_block;

typedef struct	s_all // структура для всего вместе
{
	t_win		*win; 
	t_plr		*plr;
	char		**map;
}				  t_all;

t_all	*init_game(char **argv);
int		destroy_game(t_all *all, int exit_code);
char	**make_map(t_list **head, int size);
char	**parse_map(char **argv);
int		is_player(t_all *all, char ch);
int		set_player(t_all *all);
void	draw_mini_map(t_all *all);
void	printerror(int code);
int		move(int key, t_all *all);
int		check_map(char **map);
void	ft_cast_rays(t_all *all);
int check_wall(t_all *all, int x, int y);

#endif