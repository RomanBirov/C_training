/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 10:40:45 by rbirov            #+#    #+#             */
/*   Updated: 2018/11/10 10:13:20 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_var_len(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*var;
	size_t			var_len;
	unsigned int	nmb;

	var_len = get_var_len(n);
	nmb = n;
	if (n < 0)
	{
		nmb = -n;
		var_len++;
	}
	if (!(var = ft_strnew(var_len)))
		return (0);
	var[--var_len] = nmb % 10 + '0';
	while (nmb /= 10)
		var[--var_len] = nmb % 10 + '0';
	if (n < 0)
		*(var + 0) = '-';
	return (var);
}
