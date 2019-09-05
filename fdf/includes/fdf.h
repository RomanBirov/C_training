/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 10:55:04 by rbirov            #+#    #+#             */
/*   Updated: 2019/05/31 15:32:39 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>

# define WIDTH			2000
# define HEIGHT			1000
# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_5			23
# define KEY_6			22
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_Z			6
# define KEY_X			7
# define KEY_C			8
# define KEY_V			9
# define KEY_I			34
# define KEY_P			35
# define KEY_F			3
# define KEY_G			5
# define KEY_ESCAPE		53

typedef enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct			s_zweight
{
	struct s_zweight	*next;
	int					z_w;

}						t_zweight;

typedef struct			s_xyzcoord
{
	int					x_c;
	int					y_c;
	int					z_c;
}						t_xyzcoord;

typedef struct			s_tform
{
	t_projection		projection;
	float				zmform;
	int					x_tmove;
	int					y_tmove;
	int					col;
	double				a_t;
	double				b_t;
	double				c_t;
	float				z_tform;
}						t_tform;

typedef struct			s_mload
{
	int					w_load;
	int					h_load;
	int					*array;
	int					z_low;
	int					z_high;
	int					z_load;
}						t_mload;

typedef struct			s_drawfdf
{
	void				*drawmlx;
	void				*drawwind;
	void				*drawimag;
	char				*get_data;
	int					drawpix;
	int					data_line;
	int					data_fin;
	t_tform				*form;
	t_mload				*load;
}						t_drawfdf;

void					error(char *s);
t_mload					*load_in(void);
t_drawfdf				*fdf_in(t_mload *load);
t_tform					*form_in(void);
int						ft_min(int a, int b);
void					setup_controls(t_drawfdf *fdf);
void					change_col(int key, t_drawfdf *fdf);
void					move_pic(int key, t_drawfdf *fdf);
void					zoom_pic(int key, t_drawfdf *fdf);
void					fla_pic(int key, t_drawfdf *fdf);
void					rotate_pic(int key, t_drawfdf *fdf);
void					draw(t_mload *loadmap, t_drawfdf *fdf, int y);
t_xyzcoord				new_point(int x, int y, t_mload *loadmap);
t_xyzcoord				project(t_xyzcoord p, t_drawfdf *fdf, int i);
int						read_map(const int fd, t_zweight **coord_stack,
		t_mload *loadmap, int i);

#endif
