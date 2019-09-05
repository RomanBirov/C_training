/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:40:18 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/05 10:58:45 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_mandelbrot(double x, double y, int i, t_fds *fds)
{
	double	tmp;
	double	real;
	double	imag;

	real = 0;
	imag = 0;
	x = new_point_w(x, fds->c_x, fds);
	y = new_point_h(y, fds->c_y, fds);
	while (real * real + imag * imag < 4 && i < MAX_ITER)
	{
		tmp = real * real - imag * imag + x;
		imag = 2 * real * imag + y;
		real = tmp;
		i++;
	}
	return (i);
}

int	fractal_tricorn(double x, double y, int i, t_fds *fds)
{
	double	tmp;
	double	real;
	double	imag;

	real = 0;
	imag = 0;
	x = new_point_w(x, fds->c_x, fds);
	y = new_point_h(y, fds->c_y, fds);
	while (real * real + imag * imag <= 4 && i < MAX_ITER)
	{
		tmp = real * real - imag * imag + x;
		imag = -2 * real * imag + y;
		real = tmp;
		i++;
	}
	return (i);
}

int	fractal_julia(double x, double y, int i, t_fds *fds)
{
	double	tmp;

	fds->c_real = fds->mouse_x * 4.0 / WIDTH - 2.0;
	fds->c_imag = fds->mouse_y * 4.0 / HEIGHT - 2.0;
	x = new_point_w(x, fds->c_x, fds);
	y = new_point_h(y, fds->c_y, fds);
	while (x * x + y * y < 4 && i < MAX_ITER)
	{
		tmp = x * x - y * y + fds->c_real;
		y = 2 * x * y + fds->c_imag;
		x = tmp;
		i++;
	}
	return (i);
}

int	fractal_burning_ship(double x, double y, int i, t_fds *fds)
{
	double	tmp;

	fds->c_real = fds->mouse_x * 4.0 / WIDTH - 2.0;
	fds->c_imag = fds->mouse_y * 4.0 / HEIGHT - 2.0;
	x = new_point_w(x, fds->c_x, fds);
	y = new_point_h(y, fds->c_y, fds);
	while (x * x + y * y < 4 && i < MAX_ITER)
	{
		tmp = ABS(x * x - y * y + fds->c_real);
		y = ABS(2 * x * y + fds->c_imag);
		x = tmp;
		i++;
	}
	return (i);
}
