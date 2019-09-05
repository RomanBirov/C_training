/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:27:40 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/21 16:37:54 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	char_buf(char c, t_flag *flag, int len, int i)
{
	while (i < len && i < BUFF_SIZE)
	{
		if (flag->iter + i >= BUFF_SIZE)
		{
			write(1, flag->buffer, flag->iter);
			ft_bzero(flag->buffer, BUFF_SIZE);
			flag->iter = 0;
		}
		flag->buffer[flag->iter] = c;
		flag->iter++;
		i++;
	}
}

int		find_flag(char c, t_flag *flag)
{
	parse_format_flag(flag, &c);
	if (!flag->minus)
		char_buf(flag->pad_char, flag, flag->star - 1, 0);
	char_buf(c, flag, 1, 0);
	if (flag->minus)
		char_buf(flag->pad_char, flag, flag->star - 1, 0);
	write(1, flag->buffer, flag->iter);
	return (max_int(flag->star, 1));
}

int		parse_format(char **str, t_flag *flag, va_list *va)
{
	flag->formats = **str;
	(*str)++;
	if (flag->formats == 'c' || flag->formats == 'C')
		return (set_char(va, 0, flag));
	else if (flag->formats == 's' || flag->formats == 'S')
		return (set_str(va, 0, 0, flag));
	else if (flag->formats == 'p')
		return (set_str(va, 0, 0, flag));
	else if (flag->formats == 'd')
		return (set_int(va, flag));
	else if (flag->formats == 'D')
		return (set_lint(0, va, flag));
	else if (flag->formats == 'i')
		return (set_int(va, flag));
	else if ((flag->formats == 'o' || flag->formats == 'O') ||
	(flag->formats == 'x' || flag->formats == 'X') ||
	(flag->formats == 'u' || flag->formats == 'U'))
		return (set_uint(va, flag));
	else if (flag->formats == 'f' || flag->formats == 'F')
		return (set_float(va, 0, flag));
	else if (flag->formats == 'n')
		return (set_n_str(0, va, flag));
	else if (flag->formats)
		return (find_flag(flag->formats, flag));
	return (0);
}
