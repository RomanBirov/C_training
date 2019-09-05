/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 11:51:16 by rbirov            #+#    #+#             */
/*   Updated: 2018/11/04 17:07:37 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pdst;
	const char	*psrc;

	pdst = (char *)dst;
	psrc = (const char *)src;
	if (src >= dst)
		dst = ft_memcpy(dst, src, len);
	else
	{
		pdst += len;
		psrc += len;
		while (len > 0)
		{
			*--pdst = *--psrc;
			len--;
		}
	}
	return (dst);
}
