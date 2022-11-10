/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:38:35 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/10 15:07:30 by pjerddee         ###   ########.fr       */
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

int	get_rgb(int rgb, char c)
{
	int	val;

	val = 255;
	if (c == 'r' || c == 'R')
		val = (0xFF0000 & rgb) >> 16;
	else if (c == 'g' || c == 'G')
		val = (0x00FF00 & rgb) >> 8;
	else if (c == 'b' || c == 'B')
		val = (0x0000FF & rgb);
	return (val);
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

void	get_nz(t_mlx *data)
{
	int		i;
	double	min;
	double	max;

	i = 0;
	min = 0.0;
	max = 0.0;
	while (i < data->md.nx * data->md.ny)
	{
		if ((data->map + i)->z > max)
			max = (data->map + i)->z;
		if ((data->map + i)->z < min)
			min = (data->map + i)->z;
		i++;
	}
	data->md.nz = (int)(max - min);
}
