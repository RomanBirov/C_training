/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:35:42 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/04 18:03:14 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putendl_fd("ERROR: No choose fractal. Please choose one of:", 2);
	ft_putendl_fd("1 - julia", 2);
	ft_putendl_fd("2 - mandelbrot", 2);
	ft_putendl_fd("3 - tricorn", 2);
	ft_putendl_fd("4 - burning_ship", 2);
	exit(1);
}

int		fractol_fil(char *s)
{
	if (ft_strcmp(s, "1") == 0 || ft_strcmp(s, "julia") == 0 ||
			ft_strcmp(s, "Julia") == 0 || ft_strcmp(s, "2") == 0 ||
			ft_strcmp(s, "mandelbrot") == 0 ||
			ft_strcmp(s, "Mandelbrot") == 0 ||
			ft_strcmp(s, "3") == 0 ||
			ft_strcmp(s, "tricorn") == 0 ||
			ft_strcmp(s, "Tricorn") == 0 ||
			ft_strcmp(s, "4") == 0 ||
			ft_strcmp(s, "burning_ship") == 0 ||
			ft_strcmp(s, "Burning_ship") == 0)
		return (1);
	else
		return (0);
}

int		main(int ac, char **av)
{
	t_fds	*fds;

	if (ac == 2)
	{
		if (fractol_fil(av[1]) != 1)
			ft_error();
		fds = initialize_fds(av[1]);
		fds->img = mlx_new_image(fds->mlx, WIDTH, HEIGHT);
		fds->pixel_img = mlx_get_data_addr(fds->img, &(fds->bits_on_pixel),
				&(fds->data_line), &(fds->data_end));
		key_setup(fds);
		mlx_loop_hook(fds->mlx, update_img, fds);
		mlx_loop(fds->mlx);
	}
	else
		ft_error();
}
