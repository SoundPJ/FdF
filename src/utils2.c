/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:21:28 by pjerddee          #+#    #+#             */
/*   Updated: 2022/11/10 19:57:36 by pjerddee         ###   ########.fr       */
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
	free(data->mapp);
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
	else if (keysym == K_R)
		isometric(data);
	return (0);
}

void	isometric(t_mlx *data)
{
	data->tfm.sz = 1;
	if (data->md.nx > data->md.ny)
		data->tfm.sxy = (W / data->md.nx) * 0.6;
	else
		data->tfm.sxy = (W / data->md.ny) * 0.6;
	if (data->md.nz != 0)
		data->tfm.sz = H / (2.3 * (double)data->md.nz);
	data->tfm.x = 0;
	data->tfm.y = 0;
	data->tfm.rx = 54.7;
	data->tfm.ry = 0.0;
	data->tfm.rz = -45.0;
	dup_map(data);
}

void	dup_map(t_mlx *data)
{
	int		i;

	data->mapp = malloc(sizeof(t_point) * data->md.nx * data->md.ny);
	i = 0;
	while (i < (data->md.nx * data->md.ny))
	{
		data->mapp[i] = data->map[i];
		i++;
	}
}

void	transform(t_mlx *data)
{
	int	i;

	i = 0;
	while (i < (data->md.nx * data->md.ny))
	{
		data->mapp[i] = translate(data->map[i], -(data->md.nx / 2), 'x');
		data->mapp[i] = translate(data->mapp[i], -(data->md.ny / 2), 'y');
		data->mapp[i] = scaling(data->mapp[i], data->tfm.sxy, data->tfm.sz);
		data->mapp[i] = rotate(data->mapp[i], data->tfm.rz, 'z');
		data->mapp[i] = rotate(data->mapp[i], data->tfm.ry, 'y');
		data->mapp[i] = rotate(data->mapp[i], data->tfm.rx, 'x');
		data->mapp[i] = translate(data->mapp[i], (W / 2) + data->tfm.x, 'x');
		data->mapp[i] = translate(data->mapp[i], (H / 2) + data->tfm.y, 'y');
		i++;
	}
}
