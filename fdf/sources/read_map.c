/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:25:39 by rbirov            #+#    #+#             */
/*   Updated: 2019/05/31 15:25:56 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					ft_is_num(char *str)
{
	size_t	i;
	size_t	isdig;

	i = 0;
	isdig = 0;
	while (str[i] == ' ' || str[i] == '\t' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		isdig++;
	}
	return ((!str[i] && isdig) ? 1 : 0);
}

static void			free_arr(char **arr, int i)
{
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static t_zweight	*new_coord(char *s)
{
	t_zweight	*coord;
	char		**p;

	if (!(coord = (t_zweight *)ft_memalloc(sizeof(t_zweight))))
	{
		free(coord);
		error("ERROR: not read ./fdf file");
	}
	if (!(p = ft_strsplit(s, ',')))
	{
		free_arr(p, 0);
		error("ERROR: not read ./fdf file");
	}
	if (!ft_is_num(p[0]))
	{
		free(p[0]);
		error("ERROR: not read ./fdf file");
	}
	coord->z_w = ft_atoi(p[0]);
	coord->next = NULL;
	free_arr(p, 0);
	return (coord);
}

static void			parse_line(char **coord_line, t_zweight **coord_stack,
		t_mload *loadmap, int i)
{
	t_zweight	*new;

	while (*coord_line)
	{
		new = new_coord(*(coord_line++));
		if (new)
			new->next = *coord_stack;
		*coord_stack = new;
		i++;
	}
	if (loadmap->h_load == 0)
		loadmap->w_load = i;
	else if (loadmap->w_load != i)
		error("ERROR: incorrect ./fdf file");
}

int					read_map(const int fd, t_zweight **coord_stack,
		t_mload *loadmap, int res)
{
	char	*line;
	char	**coord_line;

	while ((res = get_next_line(fd, &line)) == 1)
	{
		if (!(coord_line = ft_strsplit(line, ' ')))
			error("ERROR: not read ./fdf file");
		parse_line(coord_line, coord_stack, loadmap, 0);
		free_arr(coord_line, 0);
		ft_strdel(&line);
		loadmap->h_load++;
	}
	if (!(*coord_stack))
	{
		free(*coord_stack);
		error("ERROR: incorrect ./fdf file");
	}
	return (res);
}
