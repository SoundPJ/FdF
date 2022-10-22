/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:38:35 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/23 00:07:56 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//return 0 if error, otherwise return 1
int	map_check(int ac, char **av)
{
	int		fd;
	int		len;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("No file ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line || len != ft_strlen(line))
		line = get_next_line(fd);
	if (len != ft_strlen(line))
	{
		ft_putstr_fd("Found wrong line length. Exiting.\n", 2);
		return (0);
	}
	return (1);
}