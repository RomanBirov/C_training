/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:07:49 by rbirov            #+#    #+#             */
/*   Updated: 2018/11/04 17:30:03 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*var;
	unsigned int	i;

	i = 0;
	if (s == 0 || f == 0)
		return (0);
	var = ft_strnew(ft_strlen(s));
	if (var == 0)
		return (0);
	while (s[i] != '\0')
	{
		var[i] = f(i, s[i]);
		i++;
	}
	return (var);
}
