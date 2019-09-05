/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_filler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:14:52 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/30 18:45:05 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIS_FILLER_H
# define VIS_FILLER_H

# define WIND_HEIGHT 900
# define WIND_WEIGHT 900

# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define RED 0xFF0000

# define ESC 53

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct	s_coord
{
	float		x;
	float		y;
	float		z;
	int			put_color;
}				t_coord;

typedef struct	s_mlx
{
	void		*mlx;
	void		*mlx_window;
	void		*mlx_img;
	char		*mlx_addr;
	int			bits_per_pixel;
	int			line_size;
	int			end_of_line;
}				t_mlx;

typedef struct	s_bot
{
	char		*name_of_bot;
	int			bot_score;
}				t_bot;

typedef struct	s_fdf
{
	t_mlx		*img;
	int			map_y;
	int			map_x;
	t_coord		**map;
	t_bot		*bot1;
	t_bot		*bot2;
}				t_fdf;

void			key_set(t_fdf *bat);
char			*bot_name(char *line);
void			format_map(t_fdf *bat, char *line, int fd);
void			print_bot_names(t_fdf *bat);
int				start_battle(t_fdf *bat, int fd);
int				make_visual(t_fdf *bat);
void			put_pixel_form(int x, int y, t_fdf *bat, int color);
void			brethen_line_form(t_coord p0, t_coord p1, t_fdf *bat);
void			make_square(t_coord start, t_coord end, int color, t_fdf *bat);
void			choose_bot_square(t_fdf *bat, int x, int y);
void			battle_end(t_fdf *bat, char *line, int fd);
void			battle_result(t_fdf *bat);
void			free_str(char **str);
char			*ft_itoa(int nbr);
#endif
