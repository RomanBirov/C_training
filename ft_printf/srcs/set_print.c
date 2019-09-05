/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:29:37 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/22 13:50:54 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	str_to_buf(char *str, t_flag *flag, int i)
{
	while (str[i])
	{
		if (flag->iter + i >= BUFF_SIZE)
		{
			write(1, flag->buffer, flag->iter);
			ft_bzero((void*)flag->buffer, BUFF_SIZE);
			flag->iter = 0;
		}
		flag->buffer[flag->iter] = str[i];
		flag->iter++;
		i++;
	}
}

int		print_str(char *str, int len, int str_len, t_flag *flag)
{
	int	pad;

	parse_format_flag(flag, str);
	len = ft_strlen(str);
	if (flag->pref > 0)
		str_len = ft_strlen(flag->pref);
	pad = flag->star - len - str_len;
	if (flag->pad_char == '0' && flag->pref)
		str_to_buf(flag->pref, flag, 0);
	if (!flag->minus && flag->pad_char)
		char_buf(flag->pad_char, flag, pad, 0);
	if (flag->pad_char == ' ' && flag->pref)
		str_to_buf(flag->pref, flag, 0);
	if (flag->dot > 0 && flag->dot < len)
		char_buf(flag->pad_char, flag, flag->dot - len, 0);
	str_to_buf(str, flag, 0);
	if (flag->minus && flag->pad_char)
		char_buf(flag->pad_char, flag, pad, 0);
	write(1, flag->buffer, flag->iter);
	ft_strdel(&str);
	return (max_int(flag->star, len + str_len));
}

void	space_min_zero(int len, int pad, t_flag *flag)
{
	if (flag->pad_char == '0' && flag->pref)
		str_to_buf(flag->pref, flag, 0);
	if (!flag->minus && flag->pad_char)
		char_buf(flag->pad_char, flag, pad, 0);
	if (flag->pad_char == ' ' && flag->pref)
		str_to_buf(flag->pref, flag, 0);
	if (flag->dot > len)
		char_buf('0', flag, flag->dot - len, 0);
}

int		print_int(char *str, int len, int str_len, t_flag *flag)
{
	int	pad;

	if (*str == '-' && str++)
		flag->pref = "-";
	parse_format_flag(flag, str);
	len = ft_strlen(str);
	if (flag->pref > 0)
		str_len = ft_strlen(flag->pref);
	pad = flag->star - max_int(len, flag->dot) - str_len;
	space_min_zero(len, pad, flag);
	str_to_buf(str, flag, 0);
	if (flag->minus && flag->pad_char)
		char_buf(flag->pad_char, flag, pad, 0);
	write(1, flag->buffer, flag->iter);
	if (flag->dot > len)
		len += flag->dot - len;
	if (flag->pref)
		ft_strchr(flag->pref, '-');
	if (flag->pref && ft_strchr(flag->pref, '-'))
		free(str - 1);
	else
		free(str);
	return (max_int(flag->star, len + str_len));
}
