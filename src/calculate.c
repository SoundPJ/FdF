/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:40:47 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/01 21:57:34 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	rotate(t_point p, double dg, char axis)
{
	double		x;
	double		y;
	double		z;
	// t_point		pp;

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
	// set_coord(&pp, x, y, z);
	set_coord(&p, x, y, z);
	return (p);
}

t_point	translate(t_point p, double dist, char axis)
{
	// double		x;
	// double		y;
	// double		z;
	t_point		pp;

	if (axis == 'x' || axis == 'X')
	{
		pp.x = p.x + dist;
		pp.y = p.y;
		pp.z = p.z;
	}
	else if (axis == 'y' || axis == 'Y')
	{
		pp.x = p.x;
		pp.y = p.y + dist;
		pp.z = p.z;
	}
	else
	{
		pp.x = p.x;
		pp.y = p.y;
		pp.z = p.z + dist;
	}
	set_color(&pp, p.r, p.g, p.b);
	// set_coord(&pp, x, y, z);
	return (pp);
}

t_point	scaling(t_point	p, double sxy, double sz)
{
	double	x;
	double	y;
	double	z;

	x = (int)p.x * sxy;
	y = (int)p.y * sxy;
	z = (int)p.z * sz;
	set_coord(&p, x, y, z);
	return (p);
}
