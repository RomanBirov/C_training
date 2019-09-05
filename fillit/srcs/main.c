/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:05:27 by msydor            #+#    #+#             */
/*   Updated: 2019/01/14 12:05:30 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_make_tet_set(char *array, int index, int i, int j)
{
	char	**set;

	DEFENSE((set = (char**)malloc(sizeof(char*) * index + 1)));
	set[index] = NULL;
	while (++i < index)
	{
		DEFENSE((set[i] = (char*)malloc(sizeof(char) * 16 + 1)));
		set[i][16] = '\0';
	}
	index = -1;
	i = -1;
	while (array[++i])
	{
		if (array[i] != '\n')
			set[j][++index] = array[i];
		if (((i + 1) % 21) == 0)
		{
			index = -1;
			j++;
		}
	}
	return (set);
}

int		ft_try_fill(char **set, char **map, int i, int size)
{
	int		line;
	int		col;

	if (!set[i])
		return (1);
	line = -1;
	while (++line < size)
	{
		col = -1;
		while (++col < size)
			if (ft_check_size(map, set[i], col, line) == 1)
			{
				map = ft_put_tetrominos(map, set[i], col, line);
				if (ft_try_fill(set, map, i + 1, size) == 1)
					return (1);
				ft_back_up(map, set[i], -1, -1);
			}
	}
	return (0);
}

void	ft_fillit(char **tetris, int fd)
{
	char	**map;
	int		size;
	int		i;

	size = 2;
	map = NULL;
	map = ft_new_map(size, map, 0, 0);
	while (ft_try_fill(tetris, map, 0, size) == 0)
		map = ft_new_map(++size, map, 0, 0);
	i = -1;
	while (map[++i])
		ft_putendl(map[i]);
	ft_free_map(map);
	close(fd);
}

void	ft_read_file(int *fd, int argc, char *name, char *buf)
{
	int		end;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(0);
	}
	*fd = open(name, O_RDONLY);
	if (*fd == -1)
		error();
	end = read(*fd, buf, BUFF_SIZE + 1);
	if (end == -1)
		error();
	buf[end] = '\0';
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**tetris;
	char	buf[BUFF_SIZE + 1];

	ft_read_file(&fd, argc, argv[1], &buf[0]);
	ft_check_count_chr(buf, -1, 0, 0);
	ft_check_near(buf, -1);
	tetris = NULL;
	tetris = ft_make_tet_set(buf, ft_count_figures(buf), -1, 0);
	ft_validate(tetris, -1, -1, 0);
	ft_make_diffirent(tetris, -1, -1);
	ft_fillit(tetris, fd);
	return (0);
}
