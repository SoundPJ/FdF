/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:38:35 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/24 17:34:58 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//return 0 if error, otherwise return number of line
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
	return (0);
}

// t_point	**map_extract(int fd)
// {
// 	t_point	**map;
// 	char	**data;
// 	char	*s;
// 	int		i;

// 	s = get_next_line(fd);
// 	data = ft_split(s, ' ');
// 	i = 0;
// 	while (data[i])
// 		i++;
// 	map = malloc(sizeof(t_point *) * i);
// }
