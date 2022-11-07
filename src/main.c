/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:41:53 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/07 17:12:25 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	t_map	md;
	t_point	*map;
	(void)	ac;

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
		printf("x y z, %d\t%d\t%d\n", md.nx, md.ny, md.nz);
		i = 0;
		while (i < (md.nx * md.ny))
		{
			map[i] = translate(map[i], -(md.nx / 2), 'x');
			map[i] = translate(map[i], -(md.ny / 2), 'y');
			if (md.nx > md.ny)
				map[i] = scaling(map[i], (WIDTH / md.nx) * 0.8, 2);
			else
				map[i] = scaling(map[i], (WIDTH / md.ny) * 0.8, 2);
			map[i] = rotate(map[i], 45.0, 'z');
			map[i] = rotate(map[i], 54.7, 'x');
			map[i] = translate(map[i], WIDTH / 2, 'x');
			map[i] = translate(map[i], HEIGHT / 2, 'y');
			i++;
		}
		put_img(map, md);
		free(map);
	}
}

// int	main(void)
// {
// 	t_mlx	data;

// 	data.mlx_ptr = mlx_init();
// 	if (data.mlx_ptr == NULL)
// 		return (MLX_ERROR);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "FdF");
// 	if (data.win_ptr == NULL)
// 	{
// 		free(data.win_ptr);
// 		return (MLX_ERROR);
// 	}
// 	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
// 	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
// 	mlx_loop(data.mlx_ptr);
// 	mlx_destroy_display(data.mlx_ptr);
// 	free(data.mlx_ptr);
// }