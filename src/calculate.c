/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:40:47 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/28 00:05:46 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	rotate(t_point p, double degree, char axis)
{
	int		x;
	int		y;
	int		z;

	if (axis == 'x' || axis == 'X')
	{
		x = p.x;
		y = (cos(degree) * p.y) - (sin(degree) * p.z);
		z = (sin(degree) * p.y) + (cos(degree) * p.z);
	}
	else if (axis == 'y' || axis == 'Y')
	{
		x = (cos(degree) * p.x) + (sin(degree) * p.z);
		y = p.y;
		z = (cos(degree) * p.z) - (sin(degree) * p.x);
	}
	else if (axis == 'z' || axis == 'Z')
	{
		x = (cos(degree) * p.x) - (sin(degree) * p.y);
		y = (sin(degree) * p.x) + (cos(degree) * p.y);
		z = p.z;
	}
	return (set_point(x, y, z, p.color));
}

t_point	translate(t_point p, double dist, char axis)
{
	int		x;
	int		y;
	int		z;

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
	else if (axis == 'z' || axis == 'Z')
	{
		x = p.x;
		y = p.y;
		z = p.z + dist;
	}
	return (set_point(x, y, z, p.color));
}
