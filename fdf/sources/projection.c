/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:07:49 by rbirov            #+#    #+#             */
/*   Updated: 2019/05/31 15:25:25 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	trot_x(int *y, int *z, double a)
{
	int last_y;

	last_y = *y;
	*y = last_y * cos(a) + *z * sin(a);
	*z = -last_y * sin(a) + *z * cos(a);
}

static void	trot_y(int *x, int *z, double b)
{
	int last_x;

	last_x = *x;
	*x = last_x * cos(b) + *z * sin(b);
	*z = -last_x * sin(b) + *z * cos(b);
}

static void	trot_z(int *x, int *y, double c)
{
	int last_x;
	int last_y;

	last_x = *x;
	last_y = *y;
	*x = last_x * cos(c) - last_y * sin(c);
	*y = last_x * sin(c) + last_y * cos(c);
}

static void	t_isometric(int *x, int *y, int z)
{
	int last_x;
	int last_y;

	last_x = *x;
	last_y = *y;
	*x = (last_x - last_y) * cos(0.523599);
	*y = -z + (last_x + last_y) * sin(0.523599);
}

t_xyzcoord	project(t_xyzcoord p, t_drawfdf *fdf, int i)
{
	i = ft_min(WIDTH / fdf->load->w_load / 2, HEIGHT / fdf->load->h_load / 2);
	p.x_c *= (i - fdf->load->w_load / 2) / fdf->form->zmform;
	p.y_c *= (i - fdf->load->h_load / 2) / fdf->form->zmform;
	p.z_c *= (i / fdf->form->z_tform / 5) / fdf->form->zmform;
	if (p.z_c >= 200)
		p.z_c = 200;
	trot_x(&p.y_c, &p.z_c, fdf->form->a_t);
	trot_y(&p.x_c, &p.z_c, fdf->form->b_t);
	trot_z(&p.x_c, &p.y_c, fdf->form->c_t);
	if (fdf->form->projection == ISO)
		t_isometric(&p.x_c, &p.y_c, p.z_c);
	p.x_c += WIDTH / 2 - fdf->form->x_tmove;
	p.y_c += HEIGHT / 2 - fdf->form->y_tmove;
	return (p);
}
