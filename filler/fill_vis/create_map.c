/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:05:22 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/29 17:20:22 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_filler.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	create_map(t_fdf *bat, char *line)
{
	int		y;
	char	**str;

	y = 0;
	str = ft_strsplit(line, ' ');
	bat->map_y = ft_atoi(str[1]);
	bat->map_x = ft_atoi(str[2]);
	free_str(str);
	if (!(bat->map = (t_coord **)ft_memalloc(sizeof(t_coord *) * bat->map_y)))
		free(bat->map);
	while (y < bat->map_y)
	{
		if (!(bat->map[y] = (t_coord *)ft_memalloc(sizeof(t_coord) *
						bat->map_x)))
			free(bat->map[y]);
		y++;
	}
}

void	map_matrix(t_fdf *bat, char *line, float mult, int fd)
{
	int		i;
	int		x;
	char	**map;

	i = -1;
	while (++i < bat->map_y)
	{
		get_next_line(fd, &line);
		map = ft_strsplit(line, ' ');
		x = -1;
		while (++x < bat->map_x)
		{
			bat->map[i][x].x = (x - (bat->map_x / 2)) * mult;
			bat->map[i][x].y = (i - (bat->map_y / 2)) * mult;
			bat->map[i][x].z = map[1][x];
		}
		free_str(map);
		ft_strdel(&line);
	}
}

void	format_map(t_fdf *bat, char *line, int fd)
{
	static int	flag = 0;
	int			mult;

	if (flag == 0)
		create_map(bat, line);
	ft_strdel(&line);
	if (bat->map_x > bat->map_y)
		mult = (WIND_WEIGHT / bat->map_x) / 4 * 3;
	else
		mult = (WIND_WEIGHT / bat->map_y) / 4 * 3;
	get_next_line(fd, &line);
	ft_strdel(&line);
	map_matrix(bat, line, mult, fd);
	flag = 1;
}
