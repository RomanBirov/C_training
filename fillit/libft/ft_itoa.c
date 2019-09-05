/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:33:14 by msydor            #+#    #+#             */
/*   Updated: 2018/10/31 17:33:15 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			i;
	int			neg;
	char		*out;
	long int	clone;

	i = n < 0 ? 1 : 0;
	clone = n < 0 ? (long int)n * -1 : n;
	neg = i == 1 ? 0 : -1;
	while (clone /= 10)
		i++;
	clone = n < 0 ? (long int)n * -1 : n;
	if (!(out = (char*)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	neg == 0 ? out[0] = '-' : 1;
	out[i + 1] = '\0';
	while (i > neg)
	{
		out[i] = '0' + (clone % 10);
		clone /= 10;
		i--;
	}
	return (out);
}
