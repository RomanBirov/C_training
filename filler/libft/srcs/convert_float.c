/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:28:47 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/21 16:16:04 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	dotfloat(int *sign, double half, long double *number, t_flag *flag)
{
	int i;

	*sign = 0;
	i = 0;
	if (*number < 0)
	{
		*number = -(*number);
		*sign = 1;
	}
	if (flag->dot < -1)
		flag->dot = 7;
	while (flag->dot >= 0 && flag->dot > i++)
		half = half / 10;
	*number = *number + half;
}

char	*convert_float(void *number, char *str, t_flag *flag)
{
	str = floatoa(*(long double*)number, 0, 0, flag);
	return (str);
}

int		set_float(va_list *va, long double number, t_flag *flag)
{
	if (flag->mod_type == MOD_L)
		number = (double)va_arg(*va, double);
	else if (flag->mod_type == MOD_LL)
		number = (long double)va_arg(*va, long double);
	else
		number = (double)va_arg(*va, double);
	return (print_int(convert_float((void*)&number, 0, flag), 0, 0, flag));
}
