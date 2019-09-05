/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:00:53 by rbirov            #+#    #+#             */
/*   Updated: 2018/11/04 17:31:47 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	char	*var;

	if (!s)
		return (0);
	i = 0;
	while (((s[i] == ' ') || (s[i] >= 9
			&& s[i] <= 13)) && (s[i] != '\0'))
		i++;
	len = ft_strlen(s);
	while (((s[len - 1] == ' ') || (s[len - 1] >= 9
			&& s[len - 1] <= 13)) && (s[i] != '\0'))
		len--;
	var = ft_strsub(s, i, len - i);
	if (var)
		return (var);
	return (0);
}
