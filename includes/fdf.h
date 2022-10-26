/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:02:38 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/26 16:10:01 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define TORAD	M_PI/180
# define WRL_ERR 2

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
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_lined {
	t_point	p1;
	int		len;
	double	deg;
	int		color;
}	t_lined;

//map_init.c
int		map_check(int fd);
void	map_extract(int fd, t_point *map);

//utils.c
int		xtoi(char *s);
int		freestrarr(char **s);
int		get_npoint(char *line);
t_point	set_point(int x, int y, char *data);

//calculate.c


//put.c
void	my_mlx_line_put(t_data *data, t_point p1, t_point p2);

#endif