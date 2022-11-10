/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:49:35 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/10 16:23:27 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	b_rotate(t_mlx *data, char axis)
{
	int	i;

	i = 0;
	while (i < (data->md.nx * data->md.ny))
	{
		data->map[i] = translate(data->map[i], -(WIDTH / 2), 'x');
		data->map[i] = translate(data->map[i], -(HEIGHT / 2), 'y');
		data->map[i] = rotate(data->map[i], 10.0, axis);
		data->map[i] = translate(data->map[i], WIDTH / 2, 'x');
		data->map[i] = translate(data->map[i], HEIGHT / 2, 'y');
		i++;
	}
}

void	b_translate(t_mlx *data, char axis, int dir)
{
	int	i;

	i = 0;
	while (i < (data->md.nx * data->md.ny))
	{
		data->map[i] = translate(data->map[i], dir * 10.0, axis);
		i++;
	}
}

void	b_scaling(t_mlx *data, int dir)
{
	int	i;

	i = 0;
	while (i < (data->md.nx * data->md.ny))
	{
		data->map[i] = translate(data->map[i], -(WIDTH / 2), 'x');
		data->map[i] = translate(data->map[i], -(HEIGHT / 2), 'y');
		data->map[i] = scaling(data->map[i], 1.0 + (dir * 0.1), 1);
		data->map[i] = translate(data->map[i], WIDTH / 2, 'x');
		data->map[i] = translate(data->map[i], HEIGHT / 2, 'y');
		i++;
	}
}

void	render_background(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			my_mlx_pixel_put(img, x++, y, color);
		++y;
	}
}
