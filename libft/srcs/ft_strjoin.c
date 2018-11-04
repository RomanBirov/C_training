/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:24:33 by rbirov            #+#    #+#             */
/*   Updated: 2018/10/31 13:23:46 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*var;
	size_t	ls1;
	size_t	ls2;

	if (s1 == '\0' || s2 == '\0')
		return (0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	var = ft_strnew(ls1 + ls2);
	if (var == '\0')
		return (0);
	var = ft_strcpy(var, s1);
	ft_strlcat(var, s2, ls1 + ls2 + 1);
	return (var);
}
