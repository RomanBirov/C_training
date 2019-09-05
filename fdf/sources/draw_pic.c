/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:10:05 by rbirov            #+#    #+#             */
/*   Updated: 2019/05/31 15:25:04 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_pos_sign(int a)
{
	if (a == 0)
		return (0);
	if (a < 0)
		a *= -1;
	return (a);
}

static void	put_pixel(t_drawfdf *fdf, int x, int y)
{
	int		i;
	int		color;

	if (fdf->form->col <= 1)
		color = 0xFF0000;
	else if (fdf->form->col == 2)
		color = 0x0000FF;
	else if (fdf->form->col == 3)
		color = 0x008000;
	else if (fdf->form->col == 4)
		color = 0xFFA500;
	else if (fdf->form->col >= 5)
		color = 0xFFFFFF;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = (x * fdf->drawpix / 8) + (y * fdf->data_line);
		fdf->get_data[i] = color;
		fdf->get_data[++i] = color >> 8;
		fdf->get_data[++i] = color >> 16;
	}
}

static void	draw_line(t_xyzcoord f, t_xyzcoord s, t_drawfdf *fdf)
{
	t_xyzcoord	delta;
	t_xyzcoord	sign;
	t_xyzcoord	cur;
	int			w[2];

	delta.x_c = ft_pos_sign(s.x_c - f.x_c);
	delta.y_c = ft_pos_sign(s.y_c - f.y_c);
	sign.x_c = f.x_c < s.x_c ? 1 : -1;
	sign.y_c = f.y_c < s.y_c ? 1 : -1;
	w[0] = delta.x_c - delta.y_c;
	cur = f;
	while (cur.x_c != s.x_c || cur.y_c != s.y_c)
	{
		put_pixel(fdf, cur.x_c, cur.y_c);
		if ((w[1] = w[0] * 2) > -delta.y_c)
		{
			w[0] -= delta.y_c;
			cur.x_c += sign.x_c;
		}
		if (w[1] < delta.x_c)
		{
			w[0] += delta.x_c;
			cur.y_c += sign.y_c;
		}
	}
}

static void	draw_background(t_drawfdf *fdf, int i)
{
	int	*image;

	ft_bzero(fdf->get_data, WIDTH * HEIGHT * (fdf->drawpix / 8));
	image = (int *)(fdf->get_data);
	while (i < HEIGHT * WIDTH)
	{
		image[i] = 0x222222;
		i++;
	}
}

void		draw(t_mload *loadmap, t_drawfdf *fdf, int y)
{
	int	x;

	draw_background(fdf, 0);
	while (y < loadmap->h_load)
	{
		x = 0;
		while (x < loadmap->w_load)
		{
			if (x != fdf->load->w_load - 1)
				draw_line(project(new_point(x, y, loadmap), fdf, 0),
					project(new_point(x + 1, y, loadmap), fdf, 0), fdf);
			if (y != fdf->load->h_load - 1)
				draw_line(project(new_point(x, y, loadmap), fdf, 0),
						project(new_point(x, y + 1, loadmap), fdf, 0), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->drawmlx, fdf->drawwind, fdf->drawimag, 0, 0);
}
