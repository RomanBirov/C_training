/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:05:27 by msydor            #+#    #+#             */
/*   Updated: 2019/01/16 11:57:28 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_make_diffirent(char **tetris, int i, int j)
{
	while (tetris[++j] != '\0')
	{
		i = -1;
		while (tetris[j][++i])
		{
			if (tetris[j][i] == '#')
				tetris[j][i] = 'A' + j;
		}
	}
	if (j + 1 > 'Z' - 'A')
		error();
}

int		ft_count_figures(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			count++;
	return ((count + 1) / 5);
}

int		ft_first_not_dot(char *str)
{
	int i;

	i = -1;
	while (str[++i] == '.')
		;
	return (i);
}

int		ft_size(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}
