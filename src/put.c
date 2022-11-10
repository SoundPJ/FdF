/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:37:05 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/10 19:54:29 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < W && y >= 0 && y < H)
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	else
		return ;
	*(unsigned int *)dst = color;
}

void	my_mlx_line_put(t_img *img, t_point p1, t_point p2)
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
		color = ((p1.r + (int)(i * (dp.r / npx))) << 16)
			+ ((p1.g + (int)(i * (dp.g / npx))) << 8)
			+ p1.b + (int)(i * (dp.b / npx));
		my_mlx_pixel_put(img, p1.x + (int)(i * (dp.x / npx)),
			p1.y + (int)(i * (dp.y / npx)), color);
		i++;
	}
}

int	render(t_mlx *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, BLACK_PIXEL);
	transform(data);
	grid_put(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

int	put_img(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, W, H, "FdF");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		exit(1);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, W, H);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, ON_KEYDOWN, 1L << 0, handle_keypress, data);
	mlx_hook(data->win_ptr, ON_DESTROY, 1L << 0, exit_fdf, data);
	mlx_loop(data->mlx_ptr);
	exit_fdf(data);
	return (0);
}

void	grid_put(t_mlx *data)
{
	int	i;

	i = 0;
	while (i < ((data->md.nx * data->md.ny) - data->md.nx))
	{
		my_mlx_line_put(&data->img, data->mapp[i], data->mapp[i + data->md.nx]);
		i++;
	}
	i = 0;
	while (i < data->md.nx * data->md.ny)
	{
		if ((i + 1) % data->md.nx != 0)
			my_mlx_line_put(&data->img, data->mapp[i], data->mapp[i + 1]);
		i++;
	}
}
