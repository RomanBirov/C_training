/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:49:55 by rbirov            #+#    #+#             */
/*   Updated: 2018/11/29 13:58:40 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	char	*pstr;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		i = 0;
		pstr = (char *)haystack;
		while (needle[i] == haystack[i] && needle[i] != '\0')
			i++;
		if (needle[i] == '\0')
			return (pstr);
		haystack++;
	}
	return (0);
}
