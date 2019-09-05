/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:47:18 by rbirov            #+#    #+#             */
/*   Updated: 2019/05/31 15:25:19 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

t_zweight	*repeat(t_zweight **stack, t_zweight *n)
{
	if (stack && *stack)
	{
		n = *stack;
		*stack = (*stack)->next;
	}
	return (n);
}

void		convert_to_array(t_zweight **stack, t_mload *loadmap, int i)
{
	t_zweight	*coord;
	int			arr_size;

	arr_size = loadmap->w_load * loadmap->h_load * sizeof(int);
	if (!(loadmap->array = (int *)ft_memalloc(arr_size)))
	{
		free(loadmap);
		error("ERROR: not conversion to array");
	}
	i = loadmap->w_load * loadmap->h_load - 1;
	while ((coord = repeat(stack, NULL)) && i >= 0)
	{
		loadmap->array[i] = coord->z_w;
		if (coord->z_w > loadmap->z_high)
			loadmap->z_high = coord->z_w;
		if (coord->z_w < loadmap->z_low)
			loadmap->z_low = coord->z_w;
		i--;
		free(coord);
	}
	loadmap->z_load = loadmap->z_high - loadmap->z_low;
}

int			main(int argc, char **argv)
{
	int			fd;
	t_mload		*load;
	t_zweight	*stack;
	t_drawfdf	*fdf;

	stack = NULL;
	if (argc == 2)
	{
		if (!((fd = open(argv[1], O_RDONLY)) >= 0))
			error("ERROR: incorrect ./fdf file");
		load = load_in();
		if (read_map(fd, &stack, load, 0) == -1)
			error("ERROR: not read ./fdf file");
		fdf = fdf_in(load);
		convert_to_array(&stack, load, 0);
		fdf->form = form_in();
		draw(fdf->load, fdf, 0);
		setup_controls(fdf);
		mlx_loop(fdf->drawmlx);
	}
	error("ERROR: no ./fdf file");
	return (0);
}
