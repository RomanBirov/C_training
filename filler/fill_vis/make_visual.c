/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_visual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:06:27 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/30 18:54:40 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_filler.h"

void	put_pixel_form(int x, int y, t_fdf *bat, int color)
{
	int	i;

	x += WIND_WEIGHT / 2;
	y += WIND_HEIGHT / 2;
	if ((x >= 0 && x < WIND_WEIGHT) && (y >= 0 && y < WIND_HEIGHT))
	{
		i = ((x * bat->img->bits_per_pixel / 8) + (y * bat->img->line_size));
		bat->img->mlx_addr[i] = color;
		bat->img->mlx_addr[++i] = color >> 8;
		bat->img->mlx_addr[++i] = color >> 16;
	}
}

void	brethen_line_form(t_coord p0, t_coord p1, t_fdf *bat)
{
	t_coord delta;
	t_coord	sign;
	t_coord	error;

	delta.x = fabsf(p1.x - p0.x);
	delta.y = fabsf(p1.y - p0.y);
	sign.x = p0.x < p1.x ? 1 : -1;
	sign.y = p0.y < p1.y ? 1 : -1;
	error.x = delta.x - delta.y;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		put_pixel_form(p0.x, p0.y, bat, WHITE);
		error.y = error.x * 2;
		if (error.y > -delta.y)
		{
			error.x -= delta.y;
			p0.x += sign.x;
		}
		if (error.y < delta.x)
		{
			error.x += delta.x;
			p0.y += sign.y;
		}
	}
}

void	flag_vis(t_fdf *bat)
{
	bat->img->mlx_img = mlx_new_image(bat->img->mlx,
			WIND_WEIGHT, WIND_HEIGHT);
	bat->img->mlx_addr = mlx_get_data_addr(bat->img->mlx_img,
			&bat->img->bits_per_pixel, &bat->img->line_size,
			&bat->img->end_of_line);
}

int		make_visual(t_fdf *bat)
{
	int			*i;
	int			y;
	int			x;
	static int	flag = 0;

	if (flag == 1)
		flag_vis(bat);
	i = (int *)bat->img->mlx_addr;
	y = -1;
	while (++y < bat->map_y)
	{
		x = -1;
		while (++x < bat->map_x)
		{
			put_pixel_form(bat->map[y][x].x, bat->map[y][x].y,
					bat, bat->map[y][x].put_color);
			choose_bot_square(bat, x, y);
		}
	}
	flag = 1;
	return (0);
}
