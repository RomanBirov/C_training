/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:16:00 by rbirov            #+#    #+#             */
/*   Updated: 2018/11/04 17:10:13 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s1);
	if ((dup = (char*)malloc(size + 1)))
	{
		ft_memcpy(dup, s1, size);
		dup[size] = '\0';
		return (dup);
	}
	return (0);
}
