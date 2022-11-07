/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:02:38 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/07 21:28:06 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define RD	3.141592/180
# define WRL_ERR 2
# define WIDTH 1920
# define HEIGHT 1080

# define MLX_ERROR 1

# include "mlx.h"
// # include "mlx_int.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
// # include <X11/keysym.h>
// # include <X11/X.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
}	t_mlx;


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
	int nx;
	int	ny;
	int	nz;
}	t_map;

//map_init.c
t_map	map_check(int fd);
void	map_extract(int fd, t_point *map);
int		get_npoint(char *line);

//utils.c
int		xtoi(char *s);
int		rgb(int r, int g, int b);
int		get_rgb(int rgb, char c);
int		freestrarr(char **s);
void	get_nz(t_point *map, t_map *md);

//utils2.c
int		exit_fdf(t_mlx *data);
int		handle_keypress(int keysym, t_mlx *data);
void	isometric(t_point *map, t_map md);

//calculate.c
t_point	rotate(t_point p, double degree, char axis);
t_point	translate(t_point p, double dist, char axis);
t_point	scaling(t_point	p, double sxy, double sz);
void	set_coord(t_point* p, double x, double y, double z);
void	set_color(t_point *p, int r, int g, int b);

//put.c
void	my_mlx_line_put(t_data *data, t_point p1, t_point p2);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	grid_put(t_data *data, t_point *map, t_map md);
int		put_img(t_point *map, t_map md);
#endif
