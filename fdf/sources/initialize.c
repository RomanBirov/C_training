/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:48:10 by rbirov            #+#    #+#             */
/*   Updated: 2019/05/31 15:25:32 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

t_mload		*load_in(void)
{
	t_mload	*m;

	if (!(m = (t_mload *)ft_memalloc(sizeof(t_mload))))
	{
		free(m);
		error("ERROR: not initialize ./fdf file");
	}
	m->w_load = 0;
	m->h_load = 0;
	m->array = NULL;
	m->z_low = 0;
	m->z_high = 0;
	m->z_load = 0;
	return (m);
}

t_drawfdf	*fdf_in(t_mload *loadmap)
{
	t_drawfdf	*fdf;

	if (!(fdf = (t_drawfdf *)ft_memalloc(sizeof(t_drawfdf))))
	{
		free(fdf);
		error("ERROR: not initialize ./fdf");
	}
	if (!(fdf->drawmlx = mlx_init()))
		error("ERROR: not initialize ./fdf");
	if (!(fdf->drawwind = mlx_new_window(fdf->drawmlx, WIDTH, HEIGHT, "FDF")))
		error("ERROR: not initialize ./fdf");
	if (!(fdf->drawimag = mlx_new_image(fdf->drawmlx, WIDTH, HEIGHT)))
		error("ERROR: not initialize ./fdf");
	fdf->get_data = mlx_get_data_addr(fdf->drawimag, &(fdf->drawpix),
			&(fdf->data_line), &(fdf->data_fin));
	fdf->load = loadmap;
	return (fdf);
}

t_tform		*form_in(void)
{
	t_tform	*c;

	if (!(c = (t_tform *)ft_memalloc(sizeof(t_tform))))
	{
		free(c);
		error("ERROR: camera not initialize");
	}
	c->col = 1;
	c->zmform = 1;
	c->x_tmove = 0;
	c->y_tmove = 0;
	c->a_t = 0;
	c->b_t = 0;
	c->c_t = 0;
	c->z_tform = 1;
	return (c);
}
