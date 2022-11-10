/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:41:53 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/10 19:32:15 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int		fd;
	t_mlx	data;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("No file ", 2);
			ft_putendl_fd(av[1], 2);
			return (0);
		}
		data.md = map_check(fd);
		if (data.md.nx > 0 && data.md.ny > 0)
		{
			data.map = malloc(sizeof(t_point) * data.md.nx * data.md.ny);
			if (data.map == NULL)
				return (0);
			map_extract(open(av[1], O_RDONLY), data.map);
			get_nz(&data);
			isometric(&data);
			put_img(&data);
		}
	}
}
