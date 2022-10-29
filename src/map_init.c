/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:54:13 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/30 02:10:41 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_pointc(t_point *map, int x, int y, char *data);
static t_map	set_mapdata(int sx, int sy, int sz);

//return -1 if error, otherwise return number of points
t_map	map_check(int fd)
{
	int			npoint;
	char		*line;
	int			nline;
	int			error;

	nline = 0;
	error = 0;
	line = get_next_line(fd);
	npoint = get_npoint(line);
	while (line && ++nline)
	{
		if (npoint != get_npoint(line))
			error = WRL_ERR;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (error == 0)
		return (set_mapdata(npoint, nline, 0));
	else if (error == WRL_ERR)
		ft_putstr_fd("Found wrong line length. Exiting.\n", 2);
	return (set_mapdata(-1, -1, -1));
}

void	map_extract(int fd, t_point *map)
{
	char	**data;
	char	*s;
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	s = get_next_line(fd);
	while (s)
	{
		data = ft_split(s, ' ');
		free(s);
		x = 0;
		while (data[x + 1])
		{
			set_pointc(map + i, x, y, data[x]);
			i++;
			x++;
		}
		y++;
		s = get_next_line(fd);
		freestrarr(data);
	}
	close(fd);
}

static void	set_pointc(t_point *p, int x, int y, char *data)
{
	char	**zc;
	int		z;
	int		color;

	zc = ft_split(data, ',');
	z = ft_atoi(zc[0]);
	if (zc[1])
		set_color(p, );
		color = xtoi(zc[1]);
	else
	{
		r = 255;
		g = 255;
		b = 255;
	}
	freestrarr(zc);
	return (set_point(x, y, z, color));
}

static t_map	set_mapdata(int nx, int ny, int nz)
{
	t_map	map;

	map.nx = nx;
	map.ny = ny;
	map.nz = nz;
	return (map);
}
