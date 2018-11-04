/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:55:24 by rbirov            #+#    #+#             */
/*   Updated: 2018/10/29 12:49:27 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char p;
	char *ps;

	p = (char)c;
	ps = (char *)s;
	while (*ps != '\0')
		ps++;
	while (*ps != p)
	{
		if (ps == s)
			return (0);
		ps--;
	}
	return ((char *)ps);
}
