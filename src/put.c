/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:37:05 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/06 21:58:17 by pjerddee         ###   ########.fr       */
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
	t_point		dp;
	double		npx;
	int			i;
	int			color;

	dp.x = p2.x - p1.x;
	dp.y = p2.y - p1.y;
	dp.r = p2.r - p1.r;
	dp.g = p2.g - p1.g;
	dp.b = p2.b - p1.b;
	npx = (double)sqrt((double)((dp.x * dp.x) + (dp.y * dp.y)));
	i = 0;
	while (i < npx)
	{
		color = rgb(p1.r + (int)(i * (dp.r / npx)),
			p1.g + (int)(i * (dp.g / npx)), p1.b + (int)(i * (dp.b / npx)));
		my_mlx_pixel_put(data, p1.x + (int)(i * (dp.x / npx)),
			p1.y + (int)(i * (dp.y / npx)), color);
		i++;
	}
}

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	(void)	data;
	return (0);
}

int	handle_keyrelease(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->mlx_win);
	return (0);
}

int	put_img(t_point *map, t_map md)
{
	t_mlx	data;
	(void)	map;
	(void)	md;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FdF");
	if (data.mlx_win == NULL)
	{
		free(data.mlx);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data.mlx, &handle_no_event, &data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	// img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 		&img.endian);
	// // grid_put(&img, map, md);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.mlx_win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
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
