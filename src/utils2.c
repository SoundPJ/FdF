/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:21:28 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/07 21:24:47 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_fdf(t_mlx *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	handle_keypress(int keysym, t_mlx *data)
{
	if (keysym == 65307)
		exit_fdf(data);
	return (0);
}

void	isometric(t_point *map, t_map md)
{
	int	i;

	i = 0;
	while (i < (md.nx * md.ny))
	{
		map[i] = translate(map[i], -(md.nx / 2), 'x');
		map[i] = translate(map[i], -(md.ny / 2), 'y');
		if (md.nx > md.ny)
			map[i] = scaling(map[i], (WIDTH / md.nx) * 0.8, 2);
		else
			map[i] = scaling(map[i], (WIDTH / md.ny) * 0.8, 2);
		map[i] = rotate(map[i], 45.0, 'z');
		map[i] = rotate(map[i], 54.7, 'x');
		map[i] = translate(map[i], WIDTH / 2, 'x');
		map[i] = translate(map[i], HEIGHT / 2, 'y');
		i++;
	}
}