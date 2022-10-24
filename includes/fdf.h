/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:02:38 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/24 23:17:25 by pjerddee         ###   ########.fr       */
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

typedef struct s_line {
	t_point	p1;
	t_point	p2;
	int	color;
}	t_line;

typedef struct s_lined {
	t_point	p1;
	int		len;
	double	deg;
	int		color;
}	t_lined;

int		map_check(int fd);
t_point	**map_extract(int fd, int nline);
t_point	set_point(int x, int y, char *data);

#endif