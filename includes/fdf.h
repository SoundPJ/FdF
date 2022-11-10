/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:02:38 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/10 20:11:01 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define RD	0.017453
# define WRL_ERR 2
# define MLX_ERROR 1
// # define W 1920
// # define H 1080
# define W 800
# define H 500
# define BLACK_PIXEL 0x000000

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

enum e_key{
	ON_KEYDOWN = 02,
	ON_DESTROY = 17,
	K_X = 0x78,
	K_Y = 0x79,
	K_Z = 0x7a,
	K_ESC = 0xff1b,
	K_UP = 0xff52,
	K_LEFT = 0xff51,
	K_DOWN = 0xff54,
	K_RIGHT = 0xff53,
	K_I = 0x69,
	K_O = 0x6f,
	K_A = 0x61,
	K_B = 0x62,
	K_C = 0x63,
	K_D = 0x64,
	K_E = 0x64,
	K_F = 0x66,
	K_G = 0x67,
	K_H = 0x68,
	K_J = 0x6a,
	K_K = 0x6b,
	K_L = 0x6c,
	K_M = 0x6d,
	K_N = 0x6e,
	K_P = 0x70,
	K_Q = 0x71,
	K_R = 0x72,
	K_S = 0x73,
	K_T = 0x74,
	K_U = 0x75,
	K_V = 0x76,
	K_W = 0x77,
};

typedef struct s_img {
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		r;
	int		g;
	int		b;
	int		rgb;
}	t_point;

typedef struct s_map {
	int	nx;
	int	ny;
	int	nz;
}	t_map;

typedef struct s_tfm
{
	double	sxy;
	double	sz;
	double	x;
	double	y;
	double	rx;
	double	ry;
	double	rz;
}	t_tfm;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_point	*map;
	t_point	*mapp;
	t_map	md;
	t_tfm	tfm;
}	t_mlx;

//map_init.c
t_map	map_check(int fd);
void	map_extract(int fd, t_point *map);
int		get_npoint(char *line);

//utils.c
int		xtoi(char *s);
int		freestrarr(char **s);
void	get_nz(t_mlx *data);

//utils2.c
int		exit_fdf(t_mlx *data);
int		handle_keypress(int keysym, t_mlx *data);
void	isometric(t_mlx *data);
void	dup_map(t_mlx *data);
void	transform(t_mlx *data);

//calculate.c
t_point	rotate(t_point p, double degree, char axis);
t_point	translate(t_point p, double dist, char axis);
t_point	scaling(t_point	p, double sxy, double sz);
void	set_coord(t_point *p, double x, double y, double z);
void	set_color(t_point *p, int r, int g, int b);

//put.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	my_mlx_line_put(t_img *data, t_point p1, t_point p2);
void	grid_put(t_mlx *data);
int		put_img(t_mlx *data);
int		render(t_mlx *data);

//bonus.c
void	render_background(t_img *img, int color);
void	b_rotate(t_mlx *data, char axis);
void	b_translate(t_mlx *data, char axis, int dir);
void	b_scaling(t_mlx *data, int dir);

#endif
