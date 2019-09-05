/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:33:42 by msydor            #+#    #+#             */
/*   Updated: 2018/10/25 21:33:43 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	while (*s2 != '\0' && n-- > 0)
		s1[i++] = *(s2++);
	s1[i] = '\0';
	return (s1);
}
