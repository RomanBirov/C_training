/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:34:55 by msydor            #+#    #+#             */
/*   Updated: 2018/10/25 21:34:56 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char u1;
	unsigned char u2;

	while (n-- > 0)
	{
		u1 = (unsigned char)*s1;
		u2 = (unsigned char)*s2;
		if (u1 != u2)
			return (u1 - u2);
		if (u1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
