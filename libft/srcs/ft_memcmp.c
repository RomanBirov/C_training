/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:22:04 by rbirov            #+#    #+#             */
/*   Updated: 2018/10/29 13:16:56 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char ps1;
	unsigned char ps2;

	while (n > 0)
	{
		ps1 = *(unsigned char *)s1++;
		ps2 = *(unsigned char *)s2++;
		if (ps1 != ps2)
			return (ps1 - ps2);
		n--;
	}
	return (0);
}
