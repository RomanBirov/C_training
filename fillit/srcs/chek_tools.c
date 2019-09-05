/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:05:27 by msydor            #+#    #+#             */
/*   Updated: 2019/01/14 12:05:30 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_count_chr(char *buf, int i, int tetromins, int dots)
{
	int		count;
	int		new_line;

	new_line = 0;
	count = ft_count_figures(buf);
	if ((int)ft_strlen(buf) != (count * 20 + count - 1))
		error();
	while (buf[++i])
	{
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			error();
		(buf[i] == '\n') ? new_line++ : 1;
		(buf[i] == '.') ? dots++ : 1;
		(buf[i] == '#') ? tetromins++ : 1;
	}
	if (dots != (count * 12) || tetromins != (count * 4) ||
			new_line != (count * 4 + count - 1))
		error();
}

void	ft_check_near(char *buf, int i)
{
	while (buf[++i])
		if (buf[i] == '#' && buf[i + 1] != '#' && buf[i - 1] != '#'
			&& buf[i + 5] != '#' && buf[i - 5] != '#')
			error();
}

int		ft_validate_figure(char *tetrominos, int j, int to_return)
{
	if ((j + 1) >= 0 && tetrominos[j + 1] == '#' && ((j + 1) % 4) == 0)
		return (to_return);
	if ((j - 1) >= 0 && tetrominos[j - 1] == '#')
		to_return++;
	if ((j - 4) >= 0 && tetrominos[j - 4] == '#')
		to_return++;
	if ((j + 1) <= 15 && tetrominos[j + 1] == '#')
		to_return++;
	if ((j + 4) <= 15 && tetrominos[j + 4] == '#')
		to_return++;
	return (to_return);
}

void	ft_validate(char **tetris, int i, int j, int hash)
{
	int	touch;
	int	not_alone;

	while (tetris[++i])
	{
		not_alone = 0;
		hash = 0;
		j = -1;
		while ((tetris[i][++j] != '\0') && (tetris[i][j] == '.' ||
					tetris[i][j] == '\n' || tetris[i][j] == '#'))
			if (tetris[i][j] == '#')
			{
				if (!((touch = ft_validate_figure(tetris[i], j, 0)) > 0))
					error();
				hash++;
				if (hash > 4)
					error();
				if (touch > not_alone)
					not_alone = touch;
			}
		if (not_alone <= 1 || tetris[i][j] != '\0')
			error();
	}
}
