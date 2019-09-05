/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_int_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:12:13 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/25 15:42:17 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		set_int(va_list *va, t_flag *flag)
{
	long long int	nbr;

	if (flag->mod_type == MOD_LL)
		nbr = (long long)va_arg(*va, long long int);
	else if (flag->mod_type == MOD_L)
		nbr = (long)va_arg(*va, long int);
	else if (flag->mod_type == MOD_H)
		nbr = (short)va_arg(*va, int);
	else if (flag->mod_type == MOD_HH)
		nbr = (signed char)va_arg(*va, int);
	else if (flag->mod_type == MOD_J)
		nbr = (intmax_t)va_arg(*va, intmax_t);
	else if (flag->mod_type == MOD_Z)
		nbr = (size_t)va_arg(*va, size_t);
	else
		nbr = (int)va_arg(*va, int);
	return (print_int(convert_int((void*)&nbr, flag), 0, 0, flag));
}

int		set_uint(va_list *va, t_flag *flag)
{
	unsigned long long int	nbr;

	flag->base = S10;
	if (flag->formats == 'o' || flag->formats == 'O')
		flag->base = S8;
	if (flag->formats == 'x')
		flag->base = S16_LOW;
	if (flag->formats == 'X')
		flag->base = S16_UP;
	if (flag->mod_type == MOD_LL || flag->formats == 'U')
		nbr = (unsigned long long int)va_arg(*va, unsigned long long int);
	else if (flag->mod_type == MOD_L || flag->formats == 'O')
		nbr = (unsigned long int)va_arg(*va, unsigned long int);
	else if (flag->mod_type == MOD_H)
		nbr = (unsigned short)va_arg(*va, unsigned int);
	else if (flag->mod_type == MOD_HH)
		nbr = (unsigned char)va_arg(*va, unsigned int);
	else if (flag->mod_type == MOD_J)
		nbr = (uintmax_t)va_arg(*va, uintmax_t);
	else if (flag->mod_type == MOD_Z)
		nbr = (ssize_t)va_arg(*va, ssize_t);
	else
		nbr = (unsigned int)va_arg(*va, unsigned int);
	return (print_int(convert_int((void*)&nbr, flag), 0, 0, flag));
}

int		set_lint(long int nbr, va_list *va, t_flag *flag)
{
	flag->base = S10;
	nbr = (long int)va_arg(*va, long int);
	return (print_int(convert_int((void*)&nbr, flag), 0, 0, flag));
}

char	*convert_int(void *nbr, t_flag *flag)
{
	char	*str;

	str = NULL;
	if (ft_strchr("oOuUxX", flag->formats))
		str = uns_long_itoa_base(*(unsigned long long int*)nbr, 2, 0,
				flag->base);
	else if (flag->formats == 'p')
		str = long_itoa_base((long long int)nbr, 2, 0, S16_LOW);
	else
		str = long_itoa_base(*(long long int*)nbr, 2, 0, S10);
	return (str);
}
