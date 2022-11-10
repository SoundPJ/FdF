/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:21:28 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/10 17:38:50 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_fdf(t_mlx *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->map);
	exit(0);
}

int	handle_keypress(int keysym, t_mlx *data)
{
	if (keysym == K_ESC)
		exit_fdf(data);
	else if (keysym == K_X)
		b_rotate(data, 'x');
	else if (keysym == K_Y)
		b_rotate(data, 'y');
	else if (keysym == K_Z)
		b_rotate(data, 'z');
	else if (keysym == K_UP)
		b_translate(data, 'y', -1);
	else if (keysym == K_DOWN)
		b_translate(data, 'y', 1);
	else if (keysym == K_RIGHT)
		b_translate(data, 'x', 1);
	else if (keysym == K_LEFT)
		b_translate(data, 'x', -1);
	else if (keysym == K_I)
		b_scaling(data, 1);
	else if (keysym == K_O)
		b_scaling(data, -1);
	return (0);
}

void	isometric(t_mlx *data)
{
	int		i;
	double	sxy;
	double	sz;

	i = 0;
	sz = 1;
	if (data->md.nx > data->md.ny)
		sxy = (WIDTH / data->md.nx) * 0.6;
	else
		sxy = (WIDTH / data->md.ny) * 0.6;
	if (data->md.nz != 0)
		sz = HEIGHT / (2.3 * (double)data->md.nz);
	while (i < (data->md.nx * data->md.ny))
	{
		data->map[i] = translate(data->map[i], -(data->md.nx / 2), 'x');
		data->map[i] = translate(data->map[i], -(data->md.ny / 2), 'y');
		data->map[i] = scaling(data->map[i], sxy, sz);
		data->map[i] = rotate(data->map[i], -45.0, 'z');
		data->map[i] = rotate(data->map[i], 54.7, 'x');
		data->map[i] = translate(data->map[i], WIDTH / 2, 'x');
		data->map[i] = translate(data->map[i], HEIGHT / 2, 'y');
		i++;
	}
}
