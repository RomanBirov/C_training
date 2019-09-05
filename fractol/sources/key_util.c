/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:11:55 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/05 11:00:50 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_wheel(int key, int x, int y, t_fds *fds)
{
	if (key == MOUSE_SCROLL_DOWN)
	{
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		fds->zoom = (fds->zoom) * 1.1;
		fds->c_x += x / fds->zoom / 1.5;
		fds->c_y += y / fds->zoom / 1.5;
	}
	else if (key == MOUSE_SCROLL_UP)
		if (fds->zoom > 0)
			fds->zoom = (fds->zoom) / 1.1;
	return (update_img(fds));
}

int		mouse_update(int x, int y, t_fds *fds)
{
	fds->mouse_x = (double)x;
	fds->mouse_y = (double)y;
	return (update_img(fds));
}

int		key_util(int key, t_fds *fds)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(fds->mlx, fds->win);
		free(fds->mlx);
		exit(0);
	}
	if (key == KEY_UP || key == KEY_W)
		fds->c_y += 20;
	if (key == KEY_LEFT || key == KEY_A)
		fds->c_x += 20;
	if (key == KEY_DOWN || key == KEY_S)
		fds->c_y -= 20;
	if (key == KEY_RIGHT || key == KEY_D)
		fds->c_x -= 20;
	if (key == KEY_C)
		fds->change_color++;
	return (update_img(fds));
}

int		update_img(t_fds *fds)
{
	draw_fractal(0, -1, fds);
	menu_print(fds);
	return (0);
}
