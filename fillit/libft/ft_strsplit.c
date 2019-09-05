/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:27:34 by msydor            #+#    #+#             */
/*   Updated: 2018/10/26 20:27:35 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		t;
	char	**tab;

	i = 0;
	t = 0;
	if (!s || (!(tab = (char**)malloc(sizeof(char *)
			* (ft_words(s, c)) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[t] = ft_strndup(s + j, i - j);
			t++;
		}
	}
	tab[t] = NULL;
	return (tab);
}
