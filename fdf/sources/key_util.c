/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:11:55 by rbirov            #+#    #+#             */
/*   Updated: 2019/05/31 15:25:41 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_pic(int key, t_drawfdf *fdf)
{
	if (key == KEY_Z)
		fdf->form->zmform *= 1.1;
	else if (key == KEY_X)
		fdf->form->zmform /= 1.1;
	if (fdf->form->zmform < 0.1)
		fdf->form->zmform = 0.1;
	if (fdf->form->zmform > 10)
		fdf->form->zmform = 10;
	draw(fdf->load, fdf, 0);
}

void	fla_pic(int key, t_drawfdf *fdf)
{
	if (key == KEY_V)
		fdf->form->z_tform -= 0.1;
	else if (key == KEY_C)
		fdf->form->z_tform += 0.1;
	if (fdf->form->z_tform < 0.1)
		fdf->form->z_tform = 0.1;
	else if (fdf->form->z_tform > 200)
		fdf->form->z_tform = 200;
	draw(fdf->load, fdf, 0);
}

void	rotate_pic(int key, t_drawfdf *fdf)
{
	if (key == KEY_1)
		fdf->form->a_t += 0.05;
	else if (key == KEY_2)
		fdf->form->a_t -= 0.05;
	else if (key == KEY_4)
		fdf->form->b_t -= 0.05;
	else if (key == KEY_3)
		fdf->form->b_t += 0.05;
	else if (key == KEY_5)
		fdf->form->c_t += 0.05;
	else if (key == KEY_6)
		fdf->form->c_t -= 0.05;
	draw(fdf->load, fdf, 0);
}

void	move_pic(int key, t_drawfdf *fdf)
{
	if (key == KEY_A)
		fdf->form->x_tmove += 10;
	else if (key == KEY_D)
		fdf->form->x_tmove -= 10;
	else if (key == KEY_W)
		fdf->form->y_tmove += 10;
	else if (key == KEY_S)
		fdf->form->y_tmove -= 10;
	draw(fdf->load, fdf, 0);
}

void	change_col(int key, t_drawfdf *fdf)
{
	if (key == KEY_F && fdf->form->col < 5)
		fdf->form->col += 1;
	else if (key == KEY_G && fdf->form->col > 1)
		fdf->form->col -= 1;
	draw(fdf->load, fdf, 0);
}
