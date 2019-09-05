/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:36:21 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/04 18:12:11 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_close(void)
{
	exit(0);
	return (0);
}

void	key_setup(t_fds *fds)
{
	mlx_hook(fds->win, 2, 0, key_util, fds);
	mlx_hook(fds->win, 4, 0, mouse_wheel, fds);
	mlx_hook(fds->win, 6, 0, mouse_update, fds);
	mlx_hook(fds->win, 17, 0, ft_close, fds);
}
