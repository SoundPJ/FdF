/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:54:13 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/02 11:09:26 by pjerddee         ###   ########.fr       */
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
	printf("npoint, nline : %d\t%d\n", npoint, nline);
	if (error == 0)
		return (set_mapdata(npoint, nline, 0));
	else if (error == WRL_ERR)
		ft_putstr_fd("Found wrong line length. Exiting.\n", 2);
	return (set_mapdata(-1, -1, -1));
}

int	get_npoint(char *line)
{
	int		i;
	char	**arr;
	char	*trimmed;

	i = 0;
	trimmed = ft_strtrim(line, " \n");
	arr = ft_split(trimmed, ' ');
	free(trimmed);
	while (arr[i])
		i++;
	freestrarr(arr);
	return (i);
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
		while (data[x])
		{
			set_pointc(map + i++, x, y, data[x]);
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

	zc = ft_split(data, ',');
	z = ft_atoi(zc[0]);
	if (zc[1])
	{
		p->rgb = xtoi(zc[1]);
		p->r = get_rgb(p->rgb, 'r');
		p->g = get_rgb(p->rgb, 'g');
		p->b = get_rgb(p->rgb, 'b');
	}
	else
		set_color(p, 255, 255, 255);
	freestrarr(zc);
	set_coord(p, x, y, z);
}

static t_map	set_mapdata(int nx, int ny, int nz)
{
	t_map	map;

	map.nx = nx;
	map.ny = ny;
	map.nz = nz;
	return (map);
}
