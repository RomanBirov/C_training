/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:12:28 by rbirov            #+#    #+#             */
/*   Updated: 2018/10/29 12:59:54 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t k;

	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	k = 0;
	while (src[k] != '\0' && (i + k + 1) < dstsize)
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i + k < dstsize)
		dst[i + k] = '\0';
	return (i + ft_strlen(src));
}
