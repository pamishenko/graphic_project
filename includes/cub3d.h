/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:06:35 by ttanja            #+#    #+#             */
/*   Updated: 2022/04/03 14:41:54 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include "../includes/defines.h"

typedef struct s_draws
{
	int		tchk;
	float	r_ang;
	float	spsx;
	float	spsy;
	float	intx;
	float	inty;
	float	nhorx;
	float	nhory;
	float	hwhitx;
	float	hwhity;
	int		fhwhit;
	int		vwallhit;
	float	hdistnc;
	float	vdistnc;
	float	vwhitx;
	float	vwhity;
}					t_draws;

typedef struct s_rays
{
	float	wallhx;
	float	wallhy;
	int		down;
	int		up;
	int		right;
	int		left;
	int		hitvert;
	float	distance;
	float	angle;
}			t_rays;

typedef struct s_player
{
	float	p_x;
	float	p_y;
	char	sp;
	float	d;
	float	angle;
	int		s;
}			t_player;

typedef struct s_key
{
	int	straight;
	int	back;
	int	right;
	int	left;
	int	rightd;
	int	leftd;
	int	up;
	int	down;
	int	exit;
}		t_key;

typedef struct s_data
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		end;
}				t_data;

typedef struct s_mapa
{
	int		x_size;
	int		y_size;
	int		max;
	char	mp[2048][2048];
}			t_mapa;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
	double	t;
}			t_color;

typedef struct s_game
{
	int		w;
	int		h;
	t_color	fl;
	t_color	ceil;
}			t_game;
typedef struct s_textures
{
	char	tx_n[64];
	char	tx_s[64];
	char	tx_w[64];
	char	tx_e[64];
}			t_textures;

typedef struct s_wall
{
	int	x;
	int	y;
	int	*tex[4];
}		t_wall;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	float	x;
	float	y;
	t_data	img;
}			t_mlx;

typedef struct s_ren
{
	float		raydist;
	float		distpj;
	float		line;
	float		top;
	float		dist;
	float		bottom;
	int			i;
	float		j;
}				t_ren;

typedef struct s_all
{
	t_mlx		mlx;
	t_textures	tex;
	int			count_readed_str;
	t_mapa		map;
	t_game		game;
	t_player	pl;
	t_wall		wall;
	t_key		key;
	t_draws		draws;
	t_rays		rays[WIDTH];
	char		flag;
	int			map_line_counter;
	t_ren		rend;
}			t_all;

void	check_map_error(t_all *all);
int		check_param(char *line);
void	draw_1(int i, t_all *all);
void	draw_rays(t_all *all);
int		exit_error(int err);
int		exit_game(int key, t_all *ptr);
int		get_comma_count(char *str);
int		iswal(float y, float x, t_all *all);
void	key_init(t_all *all);
int		key_press(int key, t_all *all);
int		key_unpress(int key, t_all *all);
float	norm_angle(float rayang);
float	phifagor(float x, float y, float xd, float yd);
int		read_color(char *str, int *count, t_color *color, char *s);
int		read_textures(char *str, char *s2, t_all *all);
int		read_file_map(char *str, t_all *all);
void	render_3d(t_all *all);// испправить ошиббку
void	search_player(t_all *all);
void	set_texture(t_all *all);
void	set_max_map_line(t_all *all);
int		set_win_size(char *str, int *count, t_all *all);
int		update(t_all *all);

#endif