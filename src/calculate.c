/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:40:47 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/29 15:52:21 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	rotate(t_point p, double dg, char axis)
{
	double		x;
	double		y;
	double		z;

	if (axis == 'x' || axis == 'X')
	{
		x = p.x;
		y = (cos(dg * RD) * p.y) - (sin(dg * RD) * p.z);
		z = (sin(dg * RD) * p.y) + (cos(dg * RD) * p.z);
	}
	else if (axis == 'y' || axis == 'Y')
	{
		x = (cos(dg * RD) * p.x) + (sin(dg * RD) * p.z);
		y = p.y;
		z = (cos(dg * RD) * p.z) - (sin(dg * RD) * p.x);
	}
	else
	{
		x = (cos(dg * RD) * p.x) - (sin(dg * RD) * p.y);
		y = (sin(dg * RD) * p.x) + (cos(dg * RD) * p.y);
		z = p.z;
	}
	return (set_point(x, y, z, p.color));
}

t_point	translate(t_point p, double dist, char axis)
{
	double		x;
	double		y;
	double		z;

	if (axis == 'x' || axis == 'X')
	{
		x = p.x + dist;
		y = p.y;
		z = p.z;
	}
	else if (axis == 'y' || axis == 'Y')
	{
		x = p.x;
		y = p.y + dist;
		z = p.z;
	}
	else
	{
		x = p.x;
		y = p.y;
		z = p.z + dist;
	}
	return (set_point(x, y, z, p.color));
}

t_point	scaling(t_point	p, double sx, double sy, double sz)
{
	double	x;
	double	y;
	double	z;

	x = (int)p.x * sx;
	y = (int)p.y * sy;
	z = (int)p.z * sz;
	return (set_point(x, y, z, p.color));
}
