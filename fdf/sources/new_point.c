/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:55:29 by rbirov            #+#    #+#             */
/*   Updated: 2019/05/31 15:25:49 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_xyzcoord	new_point(int x, int y, t_mload *loadmap)
{
	t_xyzcoord	value;
	int			i;

	i = get_index(x, y, loadmap->w_load);
	value.x_c = x;
	value.y_c = y;
	value.z_c = loadmap->array[i];
	return (value);
}
