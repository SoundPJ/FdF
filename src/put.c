/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:37:05 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/26 15:55:09 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
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
	dc = p2.color - p1.color;
	npx = (long)sqrt((double)((dx * dx) + (dy * dy)));
	i = 0;
	while (i < npx)
	{
		my_mlx_pixel_put(data, p1.x + (int)(i * (dx / npx)),
			p1.y + (int)(i * (dy / npx)),
			p1.color + (int)(i * (dc / npx)));
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
