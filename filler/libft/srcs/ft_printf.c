/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:01:24 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/20 15:36:42 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	find_words_count(char *str, char c, int word_count, int i)
{
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			word_count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (word_count);
}

int	init(char **str, va_list *va, t_flag *flag)
{
	int	find;

	find = 0;
	flag->plus = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->grid = 0;
	flag->space = 0;
	flag->star = 0;
	flag->mod_type = 0;
	flag->iter = 0;
	flag->pref = 0;
	flag->dot = -2;
	flag->buffer[BUFF_SIZE_PF - 1] = '\0';
	ft_bzero(flag->buffer, BUFF_SIZE_PF);
	while (**str)
	{
		if (find_mod(str, 0, va, flag))
			find = 1;
		if (**str == '%' || ft_isalpha(**str))
			return (parse_format(str, flag, va));
		if (find == 0)
			return (0);
	}
	return (0);
}

int	word_before_percent(char **str, int result, int word_size)
{
	char	*hook;
	char	*word;
	int		word_count;

	word_count = find_words_count(*str, '{', 0, 0);
	while (word_count--)
	{
		word = ft_strchr(*str, '{');
		hook = ft_strchr(*str, '%');
		if (word && (word < hook || !hook))
		{
			write(1, *str, (int)(word - *str));
			word_size = word_size + word - *str;
			*str = word;
		}
	}
	if (hook != 0)
		result = result + hook - *str;
	else
		result = result + ft_strlen(*str);
	write(1, *str, result);
	*str = *str + result;
	result = result + word_size;
	return (result);
}

int	find_percent(va_list *va, char *format)
{
	char	*pt_format;
	t_flag	flag;

	pt_format = format;
	flag.byte = 0;
	while (*pt_format)
	{
		if (*pt_format == '%')
		{
			pt_format++;
			flag.byte += init(&pt_format, va, &flag);
		}
		else
			flag.byte += word_before_percent(&pt_format, 0, 0);
	}
	return (flag.byte);
}

int	ft_printf(char *format, ...)
{
	va_list	va;
	int		result;

	result = 0;
	if (format != 0)
	{
		va_start(va, format);
		result = find_percent(&va, format);
		va_end(va);
	}
	return (result);
}
