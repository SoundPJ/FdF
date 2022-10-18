#include "fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef	struct	s_line {
	int	x1;
	int y1;
	int x2;
	int y2;
	int color;
}				t_line;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_line_put(t_data *data, t_line line)
{
	long	npx;
	int		dx;
	int		dy;
	int		m;
	int		i;
	int		x;
	int		y;

	dx = line.x2 - line.x1;
	dy = line.y2 - line.y1;
	m = dy / dx;
	npx = (long)sqrt((double)((dx * dx) + (dy * dy)));
	i = 0;
	while (i < npx)
	{
		x = line.x1 + (i * (dx / (int) npx));
		y = line.y1 + (i * (dy / (int) npx));
		my_mlx_pixel_put(data, x, y, line.color);
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_line	line;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	line.color = 0x00FF0000;
	line.x1 = 10;
	line.x2 = 10;
	line.y1 = 10;
	line.y2 = 500;
	my_mlx_line_put(&img, line);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}