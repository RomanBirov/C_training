/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:07:49 by rbirov            #+#    #+#             */
/*   Updated: 2018/10/31 11:33:34 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*var;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (0);
	var = ft_strnew(ft_strlen(s));
	if (!var)
		return (0);
	while (s[i] != '\0')
	{
		var[i] = f(i, s[i]);
		i++;
	}
	return (var);
}
