/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:34:16 by msydor            #+#    #+#             */
/*   Updated: 2018/10/25 21:34:17 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	i++;
	while (--i >= 0)
		if (s[i] == c)
			return ((char*)s + i);
	return (NULL);
}
