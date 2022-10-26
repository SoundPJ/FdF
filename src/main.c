/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:41:53 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/26 15:35:40 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	// char	*s;
	int		fd;
	int		i;
	int		npoint;
	t_point	*map;
	// t_point	p;
	(void)	ac;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("No file ", 2);
		ft_putendl_fd(av[1], 2);
		return (0);
	}
	npoint = map_check(fd);
	if (npoint > 0)
	{
		map = malloc(sizeof(t_point) * npoint);
		if (map == NULL)
			return (0);
		map_extract(open(av[1], O_RDONLY), map);
		free(map);
		i = 0;
		while (i < npoint)
		{
			printf("%d\t%d\t%d\t%x\n", map[i].x, map[i].y, map[i].z, map[i].color);
			i++;
		}
	}
		// p = point_init(1,2,3,0x00FF0000);
	// printf("x,y,z,color = %d\t%d\t%d\t%x\n", p.x, p.y, p.z, p.color);
	// s = get_next_line(fd);
	// while (s)
	// {
	// 	printf(">>%s", s);
	// 	free(s);
	// 	s = get_next_line(fd);
	// }

	// if (nline)
		// printf("nline = %d\n", nline);
	// {

	// 	s = get_next_line(fd);
	// 	while (s)
	// 	{

	// 		s = get_next_line(fd);
	// 	}
	// }


	// init(ac, av);
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;
	// t_line	line;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 		&img.endian);
	// line.color = 0x00FF0000;
	// line.x1 = 80;
	// line.x2 = 40;
	// line.y1 = 60;
	// line.y2 = 10;
	// lined.len = 200;
	// lined.x1 = 10;
	// lined.y1 = 20;
	// lined.deg = 30;
	// lined.color = 0x00FF0000;
	// my_mlx_line_put(&img, line);
	// my_mlx_lined_put(&img, lined);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
}
