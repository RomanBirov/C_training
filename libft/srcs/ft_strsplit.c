/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 10:38:41 by rbirov            #+#    #+#             */
/*   Updated: 2018/10/31 17:05:40 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (str == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static	char	*ft_word(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	if (!(s = (char *)malloc(sizeof(s) * (ft_strlen(str)))))
		return (0);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		wrd;
	char	**s;

	i = 0;
	j = 0;
	if (c != 0 && str != '\0')
	{
		wrd = ft_count_words(str, c);
		if (!(s = (char **)malloc(sizeof(s) * (ft_count_words(str, c) + 2))))
			return (0);
		while (str[i] == c && str[i])
			i++;
		while (j < wrd && str[i])
		{
			s[j] = ft_word(str, c, &i);
			j++;
		}
		s[j] = 0;
		return (s);
	}
	return (0);
}
