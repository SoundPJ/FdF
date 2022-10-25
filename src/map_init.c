/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:54:13 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/25 23:57:24 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//return -1 if error, otherwise return number of points
int	map_check(int fd)
{
	size_t		len;
	char		*line;
	int			nline;
	int			error;

	nline = 0;
	error = 0;
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line && ++nline)
	{
		if (len != ft_strlen(line))
			error = WRL_ERR;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (error == 0)
		return (nline * len);
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
	// (void)	nline;

	x = 0;
	y = 0;
	i = 0;
	s = get_next_line(fd);
	printf("s = %s\n", s);
	while (s)
	{
		data = ft_split(s, ' ');
		while (data[x])
		{
			map[i] = set_point(x, y, data[x]);
			printf("x,y,z,color = %d\t%d\t%d\t%x\n", map[i].x, map[i].y, map[i].z, map[i].color);
			i++;
			x++;
		}
		y++;
		s = get_next_line(fd);
	}
	free(data);
}