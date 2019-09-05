/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:32:59 by msydor            #+#    #+#             */
/*   Updated: 2018/10/25 21:33:00 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*copy;

	i = 1;
	while (str[i] != '\0')
		i++;
	if (!(copy = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
		copy[i] = str[i];
	copy[i] = str[i];
	return (copy);
}
