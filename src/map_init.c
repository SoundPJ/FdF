/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:54:13 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/28 00:06:11 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	set_pointc(int x, int y, char *data);

//return -1 if error, otherwise return number of points
int	map_check(int fd)
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
		return (nline * npoint);
	else if (error == WRL_ERR)
		ft_putstr_fd("Found wrong line length. Exiting.\n", 2);
	return (-1);
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
			map[i] = set_pointc(x, y, data[x]);
			i++;
			x++;
		}
		y++;
		s = get_next_line(fd);
		freestrarr(data);
	}
	close(fd);
}

static t_point	set_pointc(int x, int y, char *data)
{
	char	**zc;
	int		z;
	int		color;

	zc = ft_split(data, ',');
	z = ft_atoi(zc[0]);
	if (zc[1])
		color = xtoi(zc[1]);
	else
		color = 0xFFFFFF;
	freestrarr(zc);
	return (set_point(x, y, z, color));
}
