/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:38:35 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/01 23:00:12 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	xtoi(char *s)
{
	int		i;
	int		num;

	num = 0;
	if (ft_strncmp(s, "0x", 2) == 0)
	{
		i = 2;
		while (s[i])
		{
			if (ft_isdigit(s[i]))
				num = (num * 16) + (s[i] - '0');
			else if (ft_isalpha(s[i]))
				num = (num * 16) + (s[i] - 'A' + 10);
			i++;
		}
	}
	return (num);
}

void	set_coord(t_point* p, double x, double y, double z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

void	set_color(t_point *p, int r, int g, int b)
{
	p->r = r;
	p->g = g;
	p->b = b;
	p->rgb = (r << 16) + (g << 8) + b;
}

int	rgb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int get_rgb(int rgb, char c)
{
	int val;

	val = 255;
	if (c == 'r' || c == 'R')
		val = (0b111111110000000000000000 & rgb) >> 16;
	else if (c == 'g' || c == 'G')
		val = (0b000000001111111100000000 & rgb) >> 8;
	else if (c == 'b' || c == 'B')
		val = (0b000000000000000011111111 & rgb);
	return (val);
}

int	get_npoint(char *line)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_split(line, ' ');
	while (arr[i])
		i++;
	freestrarr(arr);
	return (i);
}

//return 0 on success
int	freestrarr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

void	get_nz(t_point *map, t_map *md)
{
	int	i;
	double	min;
	double	max;

	i = 0;
	min = 0.0;
	max = 0.0;
	while (i < md->nx * md->ny)
	{
		if ((map + i)->z > max)
			max = (map + i)->z;
		if ((map + i)->z < min)
			min = (map + i)->z;
		i++;
	}
	md->nz = (int)(max - min);
}
