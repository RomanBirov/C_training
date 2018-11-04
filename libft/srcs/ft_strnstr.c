/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:43:07 by rbirov            #+#    #+#             */
/*   Updated: 2018/10/29 12:41:56 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*pstr;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0' && len > 0)
	{
		i = 0;
		pstr = (char *)haystack;
		while (needle[i] == haystack[i] && needle[i] != '\0' && (i - len) > 0)
			i++;
		if (needle[i] == '\0')
			return (pstr);
		haystack++;
		len--;
	}
	return (0);
}
