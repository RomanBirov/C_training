/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:08:59 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/30 18:47:25 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_filler.h"

char	*bot_name(char *line)
{
	char	*name;

	line = ft_strrchr(line, '/') + 1;
	name = ft_strnew(ft_strchr(line, '.') - line);
	name = ft_strncpy(name, line, ft_strchr(line, '.') - line);
	return (name);
}

void	print_bot_names(t_fdf *bat)
{
	mlx_string_put(bat->img->mlx, bat->img->mlx_window, 100, 100,
			WHITE, bat->bot1->name_of_bot);
	mlx_string_put(bat->img->mlx, bat->img->mlx_window, 700, 100,
			WHITE, bat->bot2->name_of_bot);
}

void	make_square(t_coord start, t_coord end, int color, t_fdf *bat)
{
	int	tm_x;

	tm_x = start.x + 1;
	start.y++;
	while (start.y < end.y)
	{
		start.x = tm_x;
		while (start.x < end.x)
		{
			put_pixel_form(start.x, start.y, bat, color);
			start.x++;
		}
		start.y++;
	}
}

void	choose_bot_square(t_fdf *bat, int x, int y)
{
	if (x + 1 < bat->map_x)
		brethen_line_form(bat->map[y][x], bat->map[y][x + 1], bat);
	if (y + 1 < bat->map_y)
		brethen_line_form(bat->map[y][x], bat->map[y + 1][x], bat);
	if (ft_strchr("xXoO", bat->map[y][x].z) && y + 1 < bat->map_y &&
			x + 1 < bat->map_x)
	{
		if (ft_strchr("xX", bat->map[y][x].z))
			make_square(bat->map[y][x], bat->map[y + 1][x + 1],
					RED, bat);
		else
			make_square(bat->map[y][x], bat->map[y + 1][x + 1],
					GREEN, bat);
	}
}
