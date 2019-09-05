/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:05:27 by msydor            #+#    #+#             */
/*   Updated: 2019/01/14 12:05:30 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_size(char **map, char *tetrominos, int i, int j)
{
	int	space_x;
	int	space_y;
	int	size;
	int	index;

	index = ft_first_not_dot(tetrominos) - 1;
	space_x = (1 + index) / 4;
	space_y = (1 + index) % 4;
	size = ft_size(map);
	while (tetrominos[++index])
		if (tetrominos[index] != '.')
		{
			if (j - space_x + (index / 4) >= size)
				return (0);
			if (i - space_y + (index % 4) >= size)
				return (0);
			if (map[j - space_x + (index / 4)]
				[(i - space_y + (index % 4))] != '.')
				return (0);
		}
	return (1);
}

char	**ft_put_tetrominos(char **map, char *tetrominos, int i, int j)
{
	int		index;
	int		space_x;
	int		space_y;

	index = ft_first_not_dot(tetrominos) - 1;
	space_x = (1 + index) / 4;
	space_y = (1 + index) % 4;
	while (tetrominos[++index])
		if (tetrominos[index] != '.')
			map[j - space_x + (index / 4)]
			[i - space_y + (index % 4)] = tetrominos[index];
	return (map);
}

char	**ft_back_up(char **map, char *tetrominos, int i, int j)
{
	char	c;

	c = tetrominos[ft_first_not_dot(tetrominos)];
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
			if (map[j][i] == c)
				map[j][i] = '.';
	}
	return (map);
}

char	**ft_new_map(int size, char **map, int i, int j)
{
	ft_free_map(map);
	DEFENSE((map = malloc(sizeof(char*) * (size + 1))));
	map[size] = NULL;
	while (i < size)
	{
		DEFENSE((map[i] = malloc(sizeof(char) * (size + 1))));
		map[i][size] = '\0';
		i++;
	}
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (j < size)
			map[i][j++] = '.';
	}
	return (map);
}

void	ft_free_map(char **map)
{
	int i;

	if (map)
	{
		i = ft_size(map);
		while (--i >= 0)
			free(map[i]);
		free(map);
	}
}
