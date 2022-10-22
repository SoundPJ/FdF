/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:37:05 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/22 23:37:46 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_line_put(t_data *data, t_line l)
{
	double		dx;
	double		dy;
	long		npx;
	int			i;

	dx = l.p2.x - l.p1.x;
	dy = l.p2.y - l.p1.y;
	npx = (long)sqrt((double)((dx * dx) + (dy * dy)));
	i = 0;
	while (i < npx)
	{
		my_mlx_pixel_put(data, l.p1.x + (int)(i * (dx / npx)),
			l.p1.y + (int)(i * (dy / npx)), l.color);
		i++;
	}
}

void	my_mlx_lined_put(t_data *data, t_lined ld)
{
	int			x2;
	int			y2;
	t_line		l;

	x2 = ld.p1.x + (ld.len * cos(rad(ld.deg)));
	y2 = ld.p1.y + (ld.len * sin(rad(ld.deg)));
	l.p1.x = ld.p1.x;
	l.p1.y = ld.p1.y;
	l.p2.x = x2;
	l.p2.y = y2;
	l.color = ld.color;
	my_mlx_line_put(data, l);
}
