/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:21:39 by rbirov            #+#    #+#             */
/*   Updated: 2018/10/31 11:33:20 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*var;

	if (len <= 0)
		return (ft_strnew(0));
	var = ft_strnew(len);
	if (s && var && ft_strlen(s) >= len)
		var = ft_strncpy(var, &s[start], len);
	return (var);
}
