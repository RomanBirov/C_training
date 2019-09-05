/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_battle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:08:00 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/29 16:55:47 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_filler.h"

void	end_game(t_fdf *bat, char *line, int f_fd)
{
	char	**map;

	map = ft_strsplit(line, ' ');
	bat->bot1->bot_score = ft_atoi(map[3]);
	free_str(map);
	get_next_line(f_fd, &line);
	map = ft_strsplit(line, ' ');
	bat->bot2->bot_score = ft_atoi(map[3]);
	free_str(map);
	free(line);
}

void	bot2_win(t_fdf *bat)
{
	mlx_string_put(bat->img->mlx, bat->img->mlx_window, 400, 800,
			WHITE, bat->bot2->name_of_bot);
	mlx_string_put(bat->img->mlx, bat->img->mlx_window, 525, 800,
			WHITE, "WIN");
	mlx_string_put(bat->img->mlx, bat->img->mlx_window, 400, 850,
			WHITE, "Press ESC to EXIT");
}

void	check_score(t_fdf *bat)
{
	if (bat->bot1->bot_score > bat->bot2->bot_score)
	{
		mlx_string_put(bat->img->mlx, bat->img->mlx_window, 400, 800,
				WHITE, bat->bot1->name_of_bot);
		mlx_string_put(bat->img->mlx, bat->img->mlx_window, 525, 800,
				WHITE, "WIN");
		mlx_string_put(bat->img->mlx, bat->img->mlx_window, 400, 850,
				WHITE, "Press ESC to EXIT");
	}
	else if (bat->bot1->bot_score < bat->bot2->bot_score)
		bot2_win(bat);
	else
		mlx_string_put(bat->img->mlx, bat->img->mlx_window, 400, 800,
				WHITE, "DRAW GAME or Error");
}

void	is_plateau(t_fdf *bat, int f_fd, char *line)
{
	format_map(bat, line, f_fd);
	make_visual(bat);
	mlx_put_image_to_window(bat->img->mlx, bat->img->mlx_window,
			bat->img->mlx_img, 0, 0);
	print_bot_names(bat);
	mlx_do_sync(bat->img->mlx);
	mlx_destroy_image(bat->img->mlx, bat->img->mlx_img);
}

int		start_battle(t_fdf *bat, int f_fd)
{
	char	*line;

	while (get_next_line(f_fd, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			is_plateau(bat, f_fd, line);
		else if (ft_strstr(line, "fin"))
		{
			end_game(bat, line, f_fd);
			check_score(bat);
			free(line);
			break ;
		}
		else
			ft_strdel(&line);
	}
	mlx_loop(bat->img->mlx);
	free(line);
	free(&bat->bot1->bot_score);
	free(&bat->bot2->bot_score);
	return (0);
}
