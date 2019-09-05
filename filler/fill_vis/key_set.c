/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:13:44 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/30 18:57:20 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_filler.h"

static int	end(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

static int	key_esc(int keycode)
{
	if (keycode == ESC)
		exit(0);
	return (0);
}

void		key_set(t_fdf *bat)
{
	mlx_hook(bat->img->mlx_window, 17, 0, end, bat);
	mlx_hook(bat->img->mlx_window, 2, 0, key_esc, bat);
}
