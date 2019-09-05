/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:43:59 by msydor            #+#    #+#             */
/*   Updated: 2018/10/25 19:44:00 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*str;
	size_t		i;
	const char	*source;

	i = 0;
	str = dst;
	source = src;
	while (i < n)
	{
		str[i] = source[i];
		i++;
	}
	return (str);
}
