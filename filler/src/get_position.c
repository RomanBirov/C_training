/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:08:51 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/29 15:58:22 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_game_data(char *line, int pad, t_piece *piece, int i)
{
	free_piece(&piece, -1);
	line = ft_strchr(line, ' ') + 1;
	piece->height = ft_atoi(line);
	piece->width = ft_atoi(ft_strchr(line, ' '));
	piece->size = piece->height * piece->width;
	if (pad > 0)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	piece->game_data = ft_memalloc(piece->height * sizeof(char *));
	while (i < piece->height)
	{
		get_next_line(0, &line);
		piece->game_data[i] = ft_strsub(line, pad, piece->width);
		i++;
		ft_strdel(&line);
	}
}

void	make_map_algoritm(t_piece *map, int x, int y, char bot2)
{
	t_coord	position;
	int		len;
	int		i;

	len = 1;
	i = 0;
	map->game_map[x][y] = 0;
	position.x = x;
	position.y = y;
	if (map->height > map->width)
		i = map->height;
	else if (map->height <= map->width)
		i = map->width;
	while (i > 0)
	{
		algoritm_set(map, position, len, bot2);
		len++;
		i--;
	}
}

void	rec_map(t_piece *map, t_bot bot2, int x, int y)
{
	while (++x < map->height)
	{
		y = -1;
		while (++y < map->width)
		{
			if (map->game_data[x][y] == bot2.bot_sym + 32 ||
					map->game_data[x][y] == bot2.bot_sym)
				make_map_algoritm(map, x, y, bot2.bot_sym);
		}
	}
}

void	create_map(t_piece *map, int x)
{
	map->game_map = (int **)malloc(map->height * sizeof(int *));
	while (++x < map->height)
	{
		map->game_map[x] = (int *)malloc(map->width * sizeof(int));
		ft_memset(map->game_map[x], 0, sizeof(map->game_map[x]));
	}
}
