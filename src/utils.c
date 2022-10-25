/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:38:35 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/25 23:57:02 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"




int xtoi(char *s)
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
				num = (num * 16) + (s[i] - '0') ;
			else if (ft_isalpha(s[i]))
				num = (num * 16) + (s[i] - 'A' + 10) ;
			i++;
		}
	}
	return (num);
}

t_point	set_point(int x, int y, char *data)
{
	t_point	p;
	char	**zc;
	p.x = x;
	p.y = y;
	zc = ft_split(data, ',');
	p.z = ft_atoi(zc[0]);
	if (zc[1])
		p.color = xtoi(zc[1]);
	else
		p.color = 0xFFFFFF;
	free(zc);
	return (p);
}
