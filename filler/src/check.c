/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:07:00 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/29 15:43:07 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		is_star(char s)
{
	if (s == '*')
		return (1);
	return (0);
}

int		piece_form(char board_position, char piece_position, char bot2)
{
	if (board_position == '\0')
		return (0);
	if ((board_position == bot2 || board_position == bot2 + 32)
			&& piece_position != '.')
		return (0);
	return (1);
}

int		check_piece(t_game *game, int x, int y, int c)
{
	int		p_x;
	int		p_y;

	p_x = -1;
	while (++p_x < game->piece.height)
	{
		p_y = -1;
		while (++p_y < game->piece.width)
		{
			if (!(piece_form(game->map.game_data[x + p_x][y + p_y],
							game->piece.game_data[p_x][p_y],
							game->bot2.bot_sym)))
				return (0);
			if ((game->map.game_data[x + p_x][y + p_y] == game->bot1.bot_sym ||
						game->map.game_data[x + p_x][y + p_y] ==
						game->bot1.bot_sym + 32) &&
					is_star(game->piece.game_data[p_x][p_y]))
				c++;
			if (game->piece.game_data[p_x][p_y] != '.')
				game->len += game->map.game_map[x + p_x][y + p_y];
		}
	}
	return (c);
}

void	check_piece_form(t_game *game, int x, int y)
{
	game->len = 0;
	if (x + game->piece.height > game->map.height ||
			y + game->piece.width > game->map.width)
		return ;
	if (check_piece(game, x, y, 0) == 1)
	{
		game->end_game = 1;
		if (game->len < game->max_rec)
		{
			game->max_rec = game->len;
			game->coord.x = x;
			game->coord.y = y;
		}
	}
}
