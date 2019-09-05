/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:00:48 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/25 16:29:30 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include "wchar.h"

# define BUFF_SIZE_PF 1024
# define S16_LOW "0123456789abcdef"
# define S16_UP "0123456789ABCDEF"
# define S8 "01234567"
# define S10 "0123456789"
# define MOD_HH 1
# define MOD_H 2
# define MOD_L 3
# define MOD_LL 4
# define MOD_J 5
# define MOD_Z 6

typedef struct	s_flag
{
	int			star;
	int			plus;
	int			minus;
	int			space;
	int			grid;
	int			zero;
	int			dot;
	int			mod_type;
	int			iter;
	int			byte;
	char		formats;
	char		pad_char;
	char		*pref;
	char		*base;
	char		buffer[BUFF_SIZE_PF];
}				t_flag;

int				ft_printf(char *format, ...);
int				find_mod(char **str, int i, va_list *va, t_flag *flag);
int				parse_flag(char **s, t_flag *flag);
int				parse_format(char **s, t_flag *flag, va_list *va);
int				max_int(int n1, int n2);
int				find_flag(char c, t_flag *flag);
void			char_buf(char c, t_flag *flag, int len, int i);
void			parse_format_flag(t_flag *flag, char *p);
int				parse_mod(char **s, t_flag *flag);
char			*floatoa(long double n, int prec, int len, t_flag *flag);
void			dotfloat(int *sign, double pi, long double *n, t_flag *flag);
int				set_float(va_list *va, long double n, t_flag *flag);
int				set_char(va_list *va, wint_t n, t_flag *flag);
int				set_int(va_list *va, t_flag *flag);
int				set_str(va_list *va, char *str, void *p, t_flag *flag);
int				set_uint(va_list *va, t_flag *flag);
int				set_n_str(int *ptr, va_list *va, t_flag *flag);
int				set_lint(long int n, va_list *va, t_flag *flag);
char			*convert_int(void *p, t_flag *flag);
char			*uns_long_itoa_base(unsigned long long int n,
		int len_str, int len_base, char *base);
char			*long_itoa_base(long long int n, int len_str,
		int len_base, char *base);
int				print_str(char *str, int len, int str_len, t_flag *flag);
int				print_int(char *str, int len, int str_len, t_flag *flag);
#endif
