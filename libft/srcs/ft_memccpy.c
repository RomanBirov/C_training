/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 11:11:24 by rbirov            #+#    #+#             */
/*   Updated: 2018/10/29 13:24:26 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	unsigned char	pc;

	pdst = (unsigned char *)d;
	psrc = (unsigned char *)s;
	pc = (unsigned char)c;
	while (n > 0)
	{
		*pdst = *psrc;
		pdst++;
		if (*psrc == pc)
			return (pdst);
		psrc++;
		n--;
	}
	return (0);
}
