/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:07:09 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/29 15:35:07 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	fill_start(t_game *game, int x, int y)
{
	while (++x < game->map.height)
	{
		y = -1;
		while (++y < game->map.width)
		{
			if (game->map.game_data[x][y] == game->bot1.bot_sym)
			{
				game->bot1.step.x = x;
				game->bot2.step.y = y;
			}
			if (game->map.game_data[x][y] == game->bot2.bot_sym)
			{
				game->bot2.step.x = x;
				game->bot2.step.y = y;
			}
		}
	}
}

void	filler(t_game *game)
{
	char	*line;
	int		ret;

	game->map.start_game = 1;
	while ((ret = get_next_line(0, &line)) > -1)
	{
		if (!ft_strncmp(line, "Plateau ", 8))
		{
			get_game_data(line, 4, &game->map, 0);
			if (game->map.start_game != 0)
			{
				fill_start(game, -1, -1);
				create_map(&game->map, -1);
			}
			rec_map(&game->map, game->bot2, -1, -1);
			game->map.start_game = 0;
		}
		if (!ft_strncmp(line, "Piece ", 6))
		{
			get_game_data(line, 0, &game->piece, 0);
			place_piece(game, -1, -1);
		}
		ft_strdel(&line);
	}
}

void	who_play_ox(t_game *game, char *line)
{
	if (ft_atoi(line + 10) == 1)
	{
		game->bot1.bot_sym = 'O';
		game->bot2.bot_sym = 'X';
	}
	if (ft_atoi(line + 10) != 1)
	{
		game->bot1.bot_sym = 'X';
		game->bot2.bot_sym = 'O';
	}
}

t_game	*init_game(char *line)
{
	t_game	*game;

	if (!(game = ft_memalloc(sizeof(t_game))))
		free(game);
	who_play_ox(game, line);
	game->algoritm = 0;
	game->len = 0;
	game->max_rec = 0;
	game->end_game = 0;
	return (game);
}

int		main(void)
{
	t_game	*game;
	char	*line;

	if (get_next_line(0, &line))
		if (line && ft_strlen(line) > 10)
		{
			game = init_game(line);
			ft_strdel(&line);
			filler(game);
		}
	return (0);
}
