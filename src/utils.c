/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:38:35 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/30 02:19:17 by pjerddee         ###   ########.fr       */
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
	return (p);
}

// void	(t_point* p, int r, int g, int b)
// {
	
// }

int	set_color(t_point* p, char *s)
{
	int		i;
	int		j;
	int		r;
	int		g;
	int		b;

	r = 0;
	if (ft_strncmp(s, "0x", 2) == 0)
	{
		i = 2;
		while (s[i] == '0')
			i++;
		j = i + 2;
		while (i < j)
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

int	get_npoint(char *line)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_split(line, ' ');
	while (arr[i])
		i++;
	freestrarr(arr);
	return (i - 1);
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
