/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:32:44 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/04 18:08:40 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_col(int i, t_fds *fds)
{
	double	f;
	char	r;
	char	g;
	char	b;

	if (!(fds->colors = (int*)malloc(sizeof(int) * MAX_COLOR_ITER)))
		free(fds->colors);
	f = 0;
	while (++i < MAX_COLOR_ITER)
	{
		r = (cos(f / 8) * MAX_COLOR_ITER);
		g = (sin(f / 8) * MAX_COLOR_ITER);
		b = (-cos(f / 8) * MAX_COLOR_ITER);
		fds->colors[i] = r << 8 | g << 16 | b << 24;
		f++;
	}
	fds->change_color = 0;
}

int		fractal_type(char *fr_type)
{
	if (ft_strcmp(fr_type, "1") == 0 ||
			ft_strcmp(fr_type, "julia") == 0 ||
			ft_strcmp(fr_type, "Julia") == 0)
		return (1);
	else if (ft_strcmp(fr_type, "2") == 0 ||
			ft_strcmp(fr_type, "mandelbrot") == 0 ||
			ft_strcmp(fr_type, "Mandelbrot") == 0)
		return (2);
	else if (ft_strcmp(fr_type, "3") == 0 ||
			ft_strcmp(fr_type, "tricorn") == 0 ||
			ft_strcmp(fr_type, "Tricorn") == 0)
		return (3);
	else if (ft_strcmp(fr_type, "4") == 0 ||
			ft_strcmp(fr_type, "burning_ship") == 0 ||
			ft_strcmp(fr_type, "Burning_ship") == 0)
		return (4);
	else
		ft_error();
	return (0);
}

t_fds	*initialize_fds(char *fr_type)
{
	t_fds	*fds;

	if (!(fds = (t_fds*)malloc(sizeof(t_fds))))
		free(fds);
	fds->mlx = mlx_init();
	fds->win = mlx_new_window(fds->mlx, WIDTH, HEIGHT, "Fractol");
	fds->fr_type = fractal_type(fr_type);
	fds->mouse_x = 0;
	fds->mouse_y = 0;
	fds->zoom = 1;
	fds->c_x = 0;
	fds->c_y = 0;
	fds->c_real = 0;
	fds->c_imag = 0;
	fds->img = mlx_new_image(fds->mlx, WIDTH, HEIGHT);
	fds->pixel_img = mlx_get_data_addr(fds->img, &(fds->bits_on_pixel),
			&(fds->data_line), &(fds->data_end));
	initialize_col(-1, fds);
	return (fds);
}
