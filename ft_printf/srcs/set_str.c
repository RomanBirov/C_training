/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:53:26 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/25 14:14:46 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		set_char(va_list *va, wint_t n, t_flag *flag)
{
	if (flag->formats == 'C' ||
			(flag->formats == 'c' && flag->mod_type == MOD_L))
		n = (wint_t)va_arg(*va, wint_t);
	else if (flag->formats == 'c')
		n = (char)va_arg(*va, int);
	else
		n = (char)'%';
	return (find_flag((char)n, flag));
}

char	*set_no_str(char *str, t_flag *flag)
{
	if (flag->formats == 'p')
		str = ft_strdup("0");
	else
		str = ft_strdup("(null)");
	return (str);
}

int		set_str(va_list *va, char *str, void *p, t_flag *flag)
{
	if (flag->formats == 's' && flag->mod_type == MOD_L)
		flag->formats = 'S';
	if (flag->formats == 'S')
		p = (wchar_t *)va_arg(*va, wchar_t *);
	if (flag->formats != 'S')
		p = (void *)va_arg(*va, void *);
	if (flag->formats == 'S' && p)
		str = ft_strdup((char *)p);
	else
	{
		if (flag->formats == 's' && p)
			str = ft_strdup((char*)p);
		else if (flag->formats == 'p')
		{
			flag->pref = "0x";
			return (print_int(convert_int(p, flag), 0, 0, flag));
		}
	}
	if (!str)
		str = set_no_str(str, flag);
	return (print_str(str, 0, 0, flag));
}

int		set_n_str(int *str, va_list *va, t_flag *flag)
{
	str = (int*)va_arg(*va, int*);
	*str = flag->byte;
	return (0);
}
