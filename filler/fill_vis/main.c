/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:43:05 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/24 18:40:19 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_filler.h"

t_mlx	*make_mlx_window(void)
{
	t_mlx	*img;

	if (!(img = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		free(img);
	img->mlx = mlx_init();
	img->mlx_window = mlx_new_window(img->mlx, WIND_WEIGHT,
			WIND_HEIGHT, "rbirov.filler");
	img->mlx_img = mlx_new_image(img->mlx, WIND_WEIGHT, WIND_HEIGHT);
	img->mlx_addr = mlx_get_data_addr(img->mlx_img, &img->bits_per_pixel,
			&img->line_size, &img->end_of_line);
	return (img);
}

void	read_data_bots(t_fdf *bat, int fd)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "exec p1"))
			bat->bot1->name_of_bot = bot_name(line);
		else if (ft_strstr(line, "exec p2"))
		{
			bat->bot2->name_of_bot = bot_name(line);
			ft_strdel(&line);
			return ;
		}
		ft_strdel(&line);
	}
}

t_fdf	*init_battle(void)
{
	t_fdf	*bat;

	if (!(bat = ft_memalloc(sizeof(t_fdf))))
		free(bat);
	bat->img = make_mlx_window();
	bat->map_y = 0;
	bat->map_x = 0;
	if (!(bat->bot1 = ft_memalloc(sizeof(t_bot))))
		free(bat->bot1);
	if (!(bat->bot2 = ft_memalloc(sizeof(t_bot))))
		free(bat->bot2);
	return (bat);
}

int		main(void)
{
	t_fdf	*bat;
	int		fd;

	fd = 0;
	bat = init_battle();
	key_set(bat);
	read_data_bots(bat, fd);
	start_battle(bat, fd);
	return (0);
}
