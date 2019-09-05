/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:11:09 by rbirov            #+#    #+#             */
/*   Updated: 2019/05/31 15:25:12 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_p(int key, t_drawfdf *fdf)
{
	fdf->form->a_t = 0;
	fdf->form->b_t = 0;
	fdf->form->c_t = 0;
	if (key == KEY_I)
		fdf->form->projection = ISO;
	else if (key == KEY_P)
		fdf->form->projection = PARALLEL;
	draw(fdf->load, fdf, 0);
}

int		key_press(int key, void *param)
{
	t_drawfdf	*fdf;

	fdf = (t_drawfdf *)param;
	if (key == KEY_ESCAPE)
		exit(0);
	if (key == KEY_Z || key == KEY_X)
		zoom_pic(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		change_p(key, fdf);
	else if (key == KEY_F || key == KEY_G)
		change_col(key, fdf);
	else if (key == KEY_W || key == KEY_A
			|| key == KEY_D || key == KEY_S)
		move_pic(key, fdf);
	else if (key == KEY_1 || key == KEY_2
			|| key == KEY_3 || key == KEY_4
			|| key == KEY_5 || key == KEY_6)
		rotate_pic(key, fdf);
	else if (key == KEY_C || key == KEY_V)
		fla_pic(key, fdf);
	return (0);
}

int		close_win(void)
{
	exit(0);
	return (0);
}

void	setup_controls(t_drawfdf *fdf)
{
	mlx_hook(fdf->drawwind, 2, 0, key_press, fdf);
	mlx_hook(fdf->drawwind, 17, 0, close_win, fdf);
}
