/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:37:05 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/30 15:45:12 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	else
		return ;
	*(unsigned int *)dst = color;
}

void	my_mlx_line_put(t_data *data, t_point p1, t_point p2)
{
	double		dx;
	double		dy;
	long		npx;
	int			dc;
	int			i;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	dc = p2.rgb - p1.rgb;
	npx = (long)sqrt((double)((dx * dx) + (dy * dy)));
	i = 0;
	while (i < npx)
	{
		my_mlx_pixel_put(data, p1.x + (int)(i * (dx / npx)),
			p1.y + (int)(i * (dy / npx)),
			p1.rgb + (int)(i * (dc / npx)));
		i++;
	}
}

// int	gradient(t_point p1, t_point p2, long npx)
// {
// 	int	rgb;


// 	return (rgb);
// }

void	put_img(t_point *map, t_map md)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	(void)	md;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	
	// my_mlx_line_put(&img, map[0], map[1]);
	// my_mlx_line_put(&img, map[1], map[2]);
	grid_put(&img, map, md);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

void grid_put(t_data *data, t_point *map, t_map md)
{
	int i;

	i = 0;
	while (i < ((md.nx * md.ny) - md.nx))
	{
		my_mlx_line_put(data, map[i], map[i + md.nx]);
		i++;
	}
	i = 0;
	while(i <= md.nx * md.ny)
	{
		if ((i + 1) % md.nx != 0)
			my_mlx_line_put(data, map[i], map[i + 1]);
		i++;
	}
}
// void	my_mlx_lined_put(t_data *data, t_lined ld)
// {
// 	int		x2;
// 	int		y2;
// 	t_point	p1;
// 	t_point	p2;

// 	x2 = ld.p1.x + (ld.len * cos(TORAD * ld.deg));
// 	y2 = ld.p1.y + (ld.len * sin(TORAD * ld.deg));
// 	p1.x = ld.p1.x;
// 	p1.y = ld.p1.y;
// 	p2.x = x2;
// 	p2.y = y2;
// 	my_mlx_line_put(data, );
// }
