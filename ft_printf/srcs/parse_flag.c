/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:40:23 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/21 16:35:36 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_flag(char **s, t_flag *flag)
{
	if (**s == '-')
		flag->minus = 1;
	else if (**s == '+')
		flag->plus = 1;
	else if (**s == '0')
		flag->zero = 1;
	else if (**s == ' ')
		flag->space = 1;
	else if (**s == '#')
		flag->grid = 1;
	else
		return (0);
	(*s)++;
	return (1);
}

void	hex_flag(t_flag *flag, char *c)
{
	if (flag->grid && *c != '0' && *c != 0)
	{
		if (flag->formats == 'x')
			flag->pref = "0x";
		else if (flag->formats == 'X')
			flag->pref = "0X";
		else if ((flag->formats == 'o' || flag->formats == 'O') &&
				(flag->dot < (int)ft_strlen(c) || flag->dot < 0))
			flag->pref = "0";
	}
}

void	parse_format_flag(t_flag *flag, char *c)
{
	hex_flag(flag, c);
	if (flag->minus || !flag->zero ||
			((flag->formats == 'd' || flag->formats == 'i') && flag->dot >= 0))
		flag->pad_char = ' ';
	else
		flag->pad_char = '0';
	if (flag->space && ((flag->pref &&
					!ft_strchr(flag->pref, '-')) || !flag->pref)
			&& (flag->formats == 'd' || flag->formats == 'i'
				|| flag->formats == 'f'))
		flag->pref = " ";
	if (flag->plus && ((flag->pref && !ft_strchr(flag->pref, '-'))
				|| !flag->pref) && (flag->formats == 'd' ||
					flag->formats == 'i' || flag->formats == 'f'))
		flag->pref = "+";
	if (((flag->dot == 0 && *c == '0') && (flag->base != S8 ||
					(flag->base == S8 && !flag->grid))) ||
			(flag->dot == 0 && flag->formats == 's'))
		*c = '\0';
	if (flag->dot > 0 && flag->dot < (int)ft_strlen(c)
			&& flag->formats == 's')
		c[flag->dot] = '\0';
}
