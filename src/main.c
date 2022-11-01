/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:41:53 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/01 22:57:01 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	// char	*s;
	int		fd;
	int		i;
	t_map	md;
	t_point	*map;
	// t_point	*mapp;
	// t_point	p;
	// t_point pp;
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
		// mapp = malloc(sizeof(t_point) * md.nx * md.ny);
		if (map == NULL)
			return (0);
		map_extract(open(av[1], O_RDONLY), map);
		get_nz(map, &md);
		i = 0;
		while (i < (md.nx * md.ny))
		{
			map[i] = translate(map[i], -(md.nx / 2), 'x');
			// printf("p->x y z r g b rgb = %f\t%f\t%f\t%d\t%d\t%d\t%d\n", map[i].x, map[i].y, map[i].z, map[i].r, map[i].g, map[i].b, map[i].rgb);
			// printf("pp->x y z r g b rgb = %f\t%f\t%f\t%d\t%d\t%d\t%d\n", mapp[i].x, mapp[i].y, mapp[i].z, mapp[i].r, mapp[i].g, mapp[i].b, mapp[i].rgb);
			map[i] = translate(map[i], -(md.ny / 2), 'y');
			if (md.nx > md.ny)
				map[i] = scaling(map[i], (WIDTH / md.nx) * 0.8, 2);
			else
				map[i] = scaling(map[i], (WIDTH / md.ny) * 0.8, 2);
			map[i] = rotate(map[i], 45.0, 'z');
			map[i] = rotate(map[i], 54.7, 'x');
			map[i] = translate(map[i], WIDTH / 2, 'x');
			map[i] = translate(map[i], HEIGHT / 2, 'y');
			// printf("(%d)\t%d\t%d\t%d\t%x\n", i, (int)map[i].x, (int)map[i].y, (int)map[i].z, map[i].color);
			i++;
		}
		// printf("pp-> %d %d %d %x\n", pp.x, pp.y, pp.z, pp.color);
		// pp = translate(p, -30.0, 'y');
		// printf("pp-> %d %d %d %x\n", pp.x, pp.y, pp.z, pp.color);
		put_img(map, md);

		free(map);
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
	// t_point	p1;
	// t_point	p2;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 		&img.endian);
	// // line.color = 0x00FF0000;
	// p1.x = 80;
	// p1.y = 60;
	// p1.color = 0x00FF0000;
	// p2.x = 400;
	// p2.y = 1000;
	// p2.color = 0x00FF0000;
	// printf("p.x, p.y, p.color = %d\t%d\t%x\n", p.x, p.y, p.color);
	// printf("pp.x, pp.y, pp.color = %d\t%d\t%x\n", pp.x, pp.y, pp.color);
	// my_mlx_pixel_put(&img, p.x, p.y, p.color);
	// my_mlx_pixel_put(&img, pp.x, pp.y, 0x00FFFFFF);
	// my_mlx_line_put(&img, p, pp);
	// my_mlx_lined_put(&img, lined);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
}
