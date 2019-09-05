/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 10:38:41 by rbirov            #+#    #+#             */
/*   Updated: 2018/11/23 10:52:18 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_of_words(const char *s, char c)
{
	int	nbwords;
	int	i;

	i = 0;
	nbwords = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			nbwords++;
		i++;
	}
	if (nbwords == 0 && s[0] != '\0')
		nbwords++;
	return (nbwords);
}

static	char	*word(const char *s, char c, int *i)
{
	char	*str;
	int		k;
	int		m;

	k = 0;
	while (s[*i] != c && s[*i])
	{
		k++;
		*i += 1;
	}
	if (!(str = (char *)malloc(sizeof(str) * (k))))
		return (0);
	m = 0;
	*i = *i - k;
	while (s[*i] != c && s[*i])
	{
		str[m] = s[*i];
		m++;
		*i += 1;
	}
	str[m] = 0;
	while (s[*i] == c && s[*i])
		*i += 1;
	return (str);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		nbwords;
	char	**ps;

	if (c && s)
	{
		i = 0;
		while (s[i] == c && s[i])
			i++;
		nbwords = count_of_words(s, c);
		if (!(ps = (char **)malloc(sizeof(ps) * (nbwords + 2))))
			return (0);
		j = 0;
		while (j <= nbwords && s[i])
		{
			ps[j] = word(s, c, &i);
			j++;
		}
		ps[j] = 0;
		return (ps);
	}
	return (0);
}
