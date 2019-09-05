/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:31:27 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/22 13:44:44 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		width(char **str, t_flag *flag, va_list *va)
{
	int	width;

	if ((width = ft_atoi(*str)) > 0 || **str == '*')
	{
		if (**str == '*')
			width = va_arg(*va, int);
		if (width < 0)
			flag->minus = 1;
		flag->star = width;
		if (width < 0)
			flag->star = -width;
		if (**str == '*')
			width = 1;
		while (width > 0 && ((*str)++))
			width = width / 10;
		return (1);
	}
	return (0);
}

int		precision(char **str, t_flag *flag, va_list *va)
{
	int	precision;

	if (**str == '.')
	{
		(*str)++;
		flag->dot = 0;
		if (((ft_isdigit(**str)) && (precision =
						ft_atoi(*str)) >= 0) || **str == '*')
		{
			if (**str == '*')
				precision = va_arg(*va, int);
			flag->dot = precision;
			if (precision < -1)
				flag->dot = -1;
			if (**str == '*')
				precision = 1;
			else if (precision == 0)
				(*str)++;
			while (precision > 0 && (*str)++)
				precision = precision / 10;
		}
		return (1);
	}
	return (0);
}

void	hljz_mod(char **str, t_flag *flag)
{
	if (**str == 'h')
		if (MOD_H > flag->mod_type)
			flag->mod_type = MOD_H;
	if (**str == 'l')
		if (MOD_L > flag->mod_type)
			flag->mod_type = MOD_L;
	if (**str == 'j')
		if (MOD_J > flag->mod_type)
			flag->mod_type = MOD_J;
	if (**str == 'z')
		if (MOD_Z > flag->mod_type)
			flag->mod_type = MOD_Z;
}

int		parse_mod(char **str, t_flag *flag)
{
	if ((**str == 'l' && *(*str + 1) == 'l')
			|| (**str == 'h' && *(*str + 1) == 'h'))
	{
		if ((**str == 'l' && *(*str + 1) == 'l'))
			if (MOD_LL > flag->mod_type)
				flag->mod_type = MOD_LL;
		if ((**str == 'h' && *(*str + 1) == 'h'))
			if (MOD_HH > flag->mod_type)
				flag->mod_type = MOD_HH;
		(*str) += 2;
	}
	else if (**str == 'h' || **str == 'l'
			|| **str == 'j' || **str == 'z')
	{
		hljz_mod(str, flag);
		(*str)++;
	}
	else
		return (0);
	return (1);
}

int		find_mod(char **str, int i, va_list *va, t_flag *flag)
{
	while (parse_flag(str, flag) || width(str, flag, va)
			|| precision(str, flag, va) || parse_mod(str, flag))
		i = 1;
	return (i);
}
