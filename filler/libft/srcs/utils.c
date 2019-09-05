/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:02:00 by rbirov            #+#    #+#             */
/*   Updated: 2019/06/25 15:09:40 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		max_int(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

char	*uns_long_itoa_base(unsigned long long int number, int len_str,
		int len_base, char *base)
{
	unsigned long long int	nbr;
	char					*str;

	nbr = number;
	len_base = ft_strlen(base);
	while (nbr /= len_base)
		len_str++;
	nbr = number;
	if (!(str = (char *)malloc(sizeof(char) * len_str)))
		return (0);
	str[--len_str] = '\0';
	while (len_str-- > 0)
	{
		str[len_str] = base[nbr % len_base];
		nbr = nbr / len_base;
	}
	return (str);
}

void	itoa_isnegative(long long int *number,
		unsigned long long int *nbr, int *len_str)
{
	if (*number < 0)
	{
		*nbr *= -1;
		*len_str += 1;
	}
}

char	*long_itoa_base(long long int number, int len_str,
		int len_base, char *base)
{
	unsigned long long int	nbr;
	char					*str;

	len_base = ft_strlen(base);
	nbr = (unsigned long long int)number;
	if (number < 0)
		nbr = -nbr;
	len_str = 2;
	while (nbr /= len_base)
		len_str++;
	nbr = (unsigned long long int)number;
	itoa_isnegative(&number, &nbr, &len_str);
	if (!(str = (char *)malloc(sizeof(char) * len_str)))
		return (0);
	str[--len_str] = '\0';
	while (len_str-- > 0)
	{
		str[len_str] = base[nbr % len_base];
		nbr = nbr / len_base;
	}
	if (number < 0)
		str[0] = '-';
	return (str);
}

char	*floatoa(long double number, int prec, int len, t_flag *flag)
{
	char	*dst;
	char	*str;
	int		sign;
	int		pos;

	dotfloat(&sign, 0.5, &number, flag);
	str = long_itoa_base((long long int)number, 2, 0, S10);
	len = ft_strlen(str);
	if (flag->dot > 0)
		prec = flag->dot;
	dst = ft_strnew(sign + len + 1 + prec);
	pos = sign;
	ft_strcpy(dst + pos, str);
	pos += len;
	if (flag->dot > 0)
		dst[pos++] = '.';
	while (pos < len + sign + prec)
	{
		dst[pos++] = ((unsigned long long int)(number * 10) % 10) + '0';
		number = number * 10;
	}
	if (sign)
		dst[0] = '-';
	ft_strdel(&str);
	return (dst);
}
