/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:07:19 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/29 16:15:30 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_piece(t_piece **piece, int i)
{
	while (++i < (*piece)->height)
		ft_strdel(&((*piece)->game_data[i]));
	free((*piece)->game_data);
	(*piece)->game_data = 0;
}

void	free_game(t_game *game, int i)
{
	while (++i < game->map.height)
	{
		ft_strdel(&game->map.game_data[i]);
		free(game->map.game_map[i]);
	}
	free(game->map.game_data);
	game->map.game_data = NULL;
	free(game->map.game_map);
	i = -1;
	while (++i < game->piece.height)
		ft_strdel(&game->piece.game_data[i]);
	free(game->piece.game_data);
	game->piece.game_data = 0;
}

void	place_piece(t_game *game, int x, int y)
{
	game->end_game = 0;
	game->max_rec = BUFF_SIZE_PF;
	while (++x < game->map.height)
	{
		y = -1;
		while (++y < game->map.width)
			check_piece_form(game, x, y);
	}
	if (game->end_game != 0)
	{
		ft_putnbr(game->coord.x);
		ft_putchar(' ');
		ft_putnbr(game->coord.y);
		ft_putchar('\n');
	}
	if (game->end_game == 0)
	{
		free_game(game, -1);
		ft_putstr("0 0\n");
		exit(0);
	}
}
