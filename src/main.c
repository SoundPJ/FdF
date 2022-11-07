/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:41:53 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/07 22:08:16 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int		fd;
	t_map	md;
	t_point	*map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("No file ", 2);
			ft_putendl_fd(av[1], 2);
			return (0);
		}
		md = map_check(fd);
		if (md.nx > 0)
		{
			map = malloc(sizeof(t_point) * md.nx * md.ny);
			if (map == NULL)
				return (0);
			map_extract(open(av[1], O_RDONLY), map);
			get_nz(map, &md);
			isometric(map, md);
			put_img(map, md);
		}
	}
}
