/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:02:38 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/03 17:08:12 by pjerddee         ###   ########.fr       */
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
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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
// t_point	set_coord(t_point *p, int x, int y, int z);

//utils.c
int		xtoi(char *s);
int		rgb(int r, int g, int b);
int		get_rgb(int rgb, char c);
int		get_npoint(char *line);
int		freestrarr(char **s);
void	get_nz(t_point *map, t_map *md);

//calculate.c
t_point	rotate(t_point p, double degree, char axis);
t_point	translate(t_point p, double dist, char axis);
t_point	scaling(t_point	p, double sxy, double sz);
void	set_coord(t_point* p, double x, double y, double z);
void	set_color(t_point *p, int r, int g, int b);


//put.c
void	my_mlx_line_put(t_data *data, t_point p1, t_point p2);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_img(t_point *map, t_map md);
void	grid_put(t_data *data, t_point *map, t_map md);


#endif
