/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:38:35 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/24 17:57:29 by pjerddee         ###   ########.fr       */
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

t_point	**map_extract(int fd, int nline)
{
	t_point	**map;
	char	**data;
	char	*s;
	int		i;

	i = 0;
	map = malloc(sizeof(t_point *) * nline);
	s = get_next_line(fd);
	{
		data = ft_split(s, ' ');
		while (data[i])
			i++;
		
	}
}
