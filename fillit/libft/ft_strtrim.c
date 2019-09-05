/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:25:27 by msydor            #+#    #+#             */
/*   Updated: 2018/10/26 19:25:28 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	char	*answer;

	if (s == NULL)
		return (NULL);
	n = ft_strlen(s);
	while (s[n - 1] == ' ' || s[n - 1] == '\t' || s[n - 1] == '\n')
		n--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		n--;
	if (n < 0)
		n = 0;
	if (!(answer = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	s += i;
	i = -1;
	while (++i < n)
		answer[i] = *s++;
	answer[i] = '\0';
	return (answer);
}
