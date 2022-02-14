/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:06:35 by ttanja            #+#    #+#             */
/*   Updated: 2022/02/14 20:36:56 by ttanja           ###   ########.fr       */
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

#define HEIGHT 1280
#define WIDTH 920 

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
#define	BLOCK_SIZE 64
#define PLAYER_SIZE 1 

#define MAP_SIZE 64 // условный размер каждого квадратика в карте

#include <libft.h>

typedef struct	s_plr //структура для игрока и луча
{
	int			px;
	int			py;
	float			dpx;
	float			dpy;
	float		dir;
	float		start;
	float		end;
	int			realAngle;
	int			fakeAngle;
	float		speed;
	float		rotSpeed;
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

typedef struct s_map
{
	int		x;
	int		y;
	int		size;
	char	*map;
} t_map;

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
}	t_win;

typedef struct	s_all // структура для всего вместе
{
	t_win			*win; 
	t_plr			*plr;
	t_map			*mapa;
	t_resolution	*resolution;
}		t_all;



t_all	*init_game(char **argv);
int		destroy_game(t_all *all, int exit_code);
char	*make_map(t_list **head, int size);
int		is_player(t_all *all, char ch);
int		set_player(t_all *all);
void	printerror(int code);
int		buttons(int key, t_all *all);
int		check_map(char **map);
int		check_wall(t_all *all, int x, int y);

void draw_map_2d(t_all *all);
void	draw_player_on_minimap(t_all *all);

void	redisplay(t_all *all);


void	set_size_map(char **argv, t_map *map);
void	set_map(int i, int j, char *line, t_map *mapa);
t_map *parser_map(char **argv, t_map	*mapa);
void ft_mlx_pixel_put(void *mlx, void *win, int x, int y, int color, int s);
void ft_mlx_pixel_put_pl(void *mlx, void *win, int x, int y, int s);
void	draw_3d(t_all *all);
int get_side_of_the_world(int x, int y, int block_size, t_all *all);
void	floor_and_ceiling(t_all *all);

#endif