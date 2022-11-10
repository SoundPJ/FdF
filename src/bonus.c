/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:49:35 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/10 19:54:08 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	b_rotate(t_mlx *data, char axis)
{
	if (axis == 'x' || axis == 'X')
		data->tfm.rx += 10;
	if (axis == 'y' || axis == 'Y')
		data->tfm.ry += 10;
	if (axis == 'z' || axis == 'Z')
		data->tfm.rz += 10;
}

void	b_translate(t_mlx *data, char axis, int dir)
{
	if (axis == 'x' || axis == 'X')
		data->tfm.x += (dir * 10);
	if (axis == 'y' || axis == 'Y')
		data->tfm.y += (dir * 10);
}

void	b_scaling(t_mlx *data, int dir)
{
	data->tfm.sxy += (dir * 0.1);
	data->tfm.sz += (dir * 0.1);
}

void	render_background(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < W)
			my_mlx_pixel_put(img, x++, y, color);
		++y;
	}
}
