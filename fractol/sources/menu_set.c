/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:31:40 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/04 18:45:52 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu_print(t_fds *fds)
{
	mlx_string_put(fds->mlx, fds->win,
			20, 10, 0x00FF0000, " _________________________________");
	mlx_string_put(fds->mlx, fds->win,
			20, 30, 0x00FF0000, "| Arrows & A,W,S,D : Move         |");
	mlx_string_put(fds->mlx, fds->win,
			20, 50, 0x00FF0000, "| C :                Change color |");
	mlx_string_put(fds->mlx, fds->win,
			20, 70, 0x00FF0000, "| Mouse wheel :      Zoom         |");
	mlx_string_put(fds->mlx, fds->win,
			20, 80, 0x00FF0000, " _________________________________");
}

double	new_point_h(double new, double tmp, t_fds *fds)
{
	new = ((4.0 * new / HEIGHT - 2.0) / fds->zoom)
		+ (tmp / HEIGHT);
	return (new);
}

double	new_point_w(double new, double tmp, t_fds *fds)
{
	new = ((4.0 * new / WIDTH - 2.0) / fds->zoom)
		+ (tmp / WIDTH);
	return (new);
}
