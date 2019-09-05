/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:06:56 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/29 15:24:58 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_piece
{
	int			height;
	int			width;
	int			size;
	int			start_game;
	int			**game_map;
	char		**game_data;
}				t_piece;

typedef	struct	s_bot
{
	char		bot_sym;
	t_coord		step;
}				t_bot;

typedef	struct	s_game
{
	t_bot		bot1;
	t_bot		bot2;
	t_coord		coord;
	t_piece		piece;
	t_piece		map;
	int			algoritm;
	int			len;
	int			max_rec;
	int			end_game;
}				t_game;

void			algoritm_set(t_piece *map,
		t_coord position, int distance, char bot2);
void			store_values(t_piece *map, int i, int j, char bot2);
void			create_map(t_piece *map, int x);
void			rec_map(t_piece *map, t_bot bot2, int x, int y);
void			check_piece_form(t_game *game, int i, int j);
void			place_piece(t_game *game, int x, int y);
void			get_game_data(char *line, int pad, t_piece *piece, int i);
void			free_piece(t_piece **piece, int i);
#endif
