/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_algoritm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:06:46 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/29 15:51:16 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	go_down(t_piece *map, t_coord p, int len, char bot2)
{
	int	i;

	i = -1;
	while (++i <= len)
	{
		if (p.y - i >= 0)
			if (map->game_data[p.x + len][p.y - i] !=
					bot2 && map->game_data[p.x + len][p.y - i] != bot2 + 32)
				if (len < map->game_map[p.x + len][p.y - i] || map->start_game)
					map->game_map[p.x + len][p.y - i] = len;
	}
	i = -1;
	while (++i <= len)
	{
		if (p.y + i < map->width)
			if (map->game_data[p.x + len][p.y + i] !=
					bot2 && map->game_data[p.x + len][p.y + i] != bot2 + 32)
				if (len < map->game_map[p.x + len][p.y + i] || map->start_game)
					map->game_map[p.x + len][p.y + i] = len;
	}
}

void	go_up(t_piece *map, t_coord p, int len, char bot2)
{
	int	i;

	i = -1;
	while (++i <= len)
	{
		if (p.y - i >= 0)
			if (map->game_data[p.x - len][p.y - i] !=
					bot2 && map->game_data[p.x - len][p.y - i] != bot2 + 32)
				if (len < map->game_map[p.x - len][p.y - i] || map->start_game)
					map->game_map[p.x - len][p.y - i] = len;
	}
	i = -1;
	while (++i <= len)
	{
		if (p.y + i < map->width)
			if (map->game_data[p.x - len][p.y + i] !=
					bot2 && map->game_data[p.x - len][p.y + i] != bot2 + 32)
				if (len < map->game_map[p.x - len][p.y + i] || map->start_game)
					map->game_map[p.x - len][p.y + i] = len;
	}
}

void	go_left(t_piece *map, t_coord p, int len, char bot2)
{
	int	i;

	i = -1;
	while (++i <= len)
	{
		if (p.x - i >= 0)
			if (map->game_data[p.x - i][p.y - len] !=
					bot2 && map->game_data[p.x - i][p.y - len] != bot2 + 32)
				if (len < map->game_map[p.x - i][p.y - len] || map->start_game)
					map->game_map[p.x - i][p.y - len] = len;
	}
	i = -1;
	while (++i <= len)
	{
		if (p.x + i < map->height)
			if (map->game_data[p.x + i][p.y - len] !=
					bot2 && map->game_data[p.x + i][p.y - len] != bot2 + 32)
				if (len < map->game_map[p.x + i][p.y - len] || map->start_game)
					map->game_map[p.x + i][p.y - len] = len;
	}
}

void	go_right(t_piece *map, t_coord p, int len, char bot2)
{
	int i;

	i = -1;
	while (++i <= len)
	{
		if (p.x - i >= 0)
			if (map->game_data[p.x - i][p.y + len] !=
					bot2 && map->game_data[p.x - i][p.y + len] != bot2 + 32)
				if (len < map->game_map[p.x - i][p.y + len] || map->start_game)
					map->game_map[p.x - i][p.y + len] = len;
	}
	i = -1;
	while (++i <= len)
	{
		if (p.x + i < map->height)
			if (map->game_data[p.x + i][p.y + len] !=
					bot2 && map->game_data[p.x + i][p.y + len] != bot2 + 32)
				if (len < map->game_map[p.x + i][p.y + len] || map->start_game)
					map->game_map[p.x + i][p.y + len] = len;
	}
}

void	algoritm_set(t_piece *map, t_coord position, int len, char bot2)
{
	if (position.x + len < map->height)
		go_down(map, position, len, bot2);
	if (position.x - len >= 0)
		go_up(map, position, len, bot2);
	if (position.y - len >= 0)
		go_left(map, position, len, bot2);
	if (position.y + len < map->width)
		go_right(map, position, len, bot2);
}
