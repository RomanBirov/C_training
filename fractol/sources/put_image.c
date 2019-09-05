/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:36:07 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/04 18:35:22 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(int x, int y, int color, t_fds *fds)
{
	int	i;

	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		i = (x * (fds->bits_on_pixel / 8)) + (y * fds->data_line);
		fds->pixel_img[i] = color;
		fds->pixel_img[++i] = color >> 8;
		fds->pixel_img[++i] = color >> 16;
	}
}

void	draw_mlx(t_fds *fds)
{
	mlx_put_image_to_window(fds->mlx, fds->win, fds->img, 0, 0);
	mlx_destroy_image(fds->mlx, fds->img);
	fds->img = mlx_new_image(fds->mlx, WIDTH, HEIGHT);
	fds->pixel_img = mlx_get_data_addr(fds->img, &(fds->bits_on_pixel),
			&(fds->data_line), &(fds->data_end));
}

void	draw_fractal(int i, int y, t_fds *fds)
{
	double	x;

	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (fds->fr_type == 1)
				i = fractal_julia(x, y, 0, fds);
			else if (fds->fr_type == 2)
				i = fractal_mandelbrot(x, y, 0, fds);
			else if (fds->fr_type == 3)
				i = fractal_tricorn(x, y, 0, fds);
			else if (fds->fr_type == 4)
				i = fractal_burning_ship(x, y, 0, fds);
			else if (fds->fr_type < 1 && fds->fr_type > 4)
				ft_error();
			if (i < MAX_ITER)
				put_pixel(x, y, fds->colors[(i +
							fds->change_color) % MAX_COLOR_ITER], fds);
		}
	}
	draw_mlx(fds);
}
