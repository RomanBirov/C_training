/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:00:19 by rbirov            #+#    #+#             */
/*   Updated: 2018/10/31 15:59:31 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *src;
	char *var;

	if (s == 0 || f == 0)
		return (0);
	src = ft_strnew(ft_strlen(s));
	if (src == '\0')
		return (0);
	var = src;
	while (*s != '\0')
		*var++ = f(*s++);
	return (src);
}
