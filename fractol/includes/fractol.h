/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:47:07 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/05 11:12:58 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>

# define ABS(x) x < 0 ? -x : x

# define MAX_ITER			64
# define MAX_COLOR_ITER		64
# define WIDTH				900
# define HEIGHT				900

# define KEY_UP				126
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_C				8
# define KEY_ESCAPE			53
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_UP	4

typedef struct	s_fds
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pixel_img;
	int			bits_on_pixel;
	int			data_line;
	int			data_end;
	int			fr_type;
	double		mouse_x;
	double		mouse_y;
	double		zoom;
	double		c_x;
	double		c_y;
	double		c_real;
	double		c_imag;
	int			*colors;
	int			change_color;
}				t_fds;

void			ft_error(void);
int				fractol_fil(char *s);
t_fds			*initialize_fds(char *fr_type);
int				fractal_type(char *fr_type);
void			initialize_col(int i, t_fds *fds);
int				ft_close(void);
void			key_setup(t_fds *fds);
int				key_util(int key, t_fds *fds);
int				mouse_wheel(int key, int x, int y, t_fds *fds);
int				mouse_update(int x, int y, t_fds *fds);
int				update_img(t_fds *fds);
void			draw_fractal(int i, int y, t_fds *fds);
void			put_pixel(int x, int y, int color, t_fds *fds);
void			draw_mlx(t_fds *fds);
void			menu_print(t_fds *fds);
double			new_point_h(double new, double tmp, t_fds *fds);
double			new_point_w(double new, double tmp, t_fds *fds);
int				fractal_mandelbrot(double x, double y, int i, t_fds *fds);
int				fractal_julia(double x, double y, int i, t_fds *fds);
int				fractal_tricorn(double x, double y, int i, t_fds *fds);
int				fractal_burning_ship(double x, double y, int i, t_fds *fds);

#endif
