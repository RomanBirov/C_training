/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:02:53 by msydor            #+#    #+#             */
/*   Updated: 2018/10/26 19:02:54 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*answer;
	size_t	i;

	if (s)
	{
		if (!(answer = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		i = -1;
		while (++i < len)
			answer[i] = s[start + i];
		answer[i] = '\0';
		return (answer);
	}
	return (NULL);
}
