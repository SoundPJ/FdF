/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:38:35 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/25 13:23:02 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//return -1 if error, otherwise return number of line
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
	if (error == 0)
		return (nline);
	else if (error == WRL_ERR)
		ft_putstr_fd("Found wrong line length. Exiting.\n", 2);
	return (-1);
}

// t_point	**map_extract(int fd, int nline)
// {
// 	t_point	*map;
// 	char	**data;
// 	char	*s;
// 	int		x;
// 	int		y;
// 	// (void)	nline;

// 	x = 0;
// 	y = 0;
// 	map = malloc(sizeof(t_point) * (nline *));
// 	s = get_next_line(fd);

// 	while (s)
// 	{
// 		data = ft_split(s, ' ');
// 		while (data[x])
// 		{
// 			set_point(x, y, data[x]);
// 			x++;
// 		}
// 		y++;
// 		s = get_next_line(fd);
// 	}
// 	return (NULL);
// }

t_point	set_point(int x, int y, char *data)
{
	t_point	p;
	char	**zc;
	p.x = x;
	p.y = y;
	zc = ft_split(data, ',');
	p.z = ft_atoi(zc[0]);
	if (zc[1])
		p.color = xtoi(zc[1]);
	else
		p.color = 0xFFFFFF;
	return (p);
}

int xtoi(char *s)
{
	int		i;
	int		num;	

	num = 0;
	if (ft_strncmp(s, "0x", 2) == 0)
	{
		i = 2;
		while (s[i])
		{
			if (ft_isdigit(s[i]))
				num = (num * 16) + (s[i] - '0') ;
			else if (ft_isalpha(s[i]))
				num = (num * 16) + (s[i] - 'A' + 10) ;
			i++;
		}
	}
	return (num);
}
