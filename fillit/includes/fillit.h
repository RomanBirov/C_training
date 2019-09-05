/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:05:27 by msydor            #+#    #+#             */
/*   Updated: 2019/01/14 12:05:30 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFF_SIZE 546
# define DEFENSE(x) if (!x) return (NULL);

int		ft_try_fill(char **tetris, char **map, int i, int size);
void	ft_fillit(char **tetris, int fd);
void	ft_read_file(int *fd, int argc, char *name, char *buf);
char	**ft_make_tet_set(char *buf, int index, int i, int j);

char	**ft_put_tetrominos(char **map, char *tetrominos, int i, int j);
char	**ft_back_up(char **map, char *tetrominos, int i, int j);
char	**ft_new_map(int size, char **map, int i, int j);
int		ft_check_size(char **map, char *tetrominos, int i, int j);
void	ft_free_map(char **map);

int		ft_validate_figure(char *tetris, int j, int to_return);
void	ft_validate(char **tetris, int i, int j, int hash);
void	ft_check_count_chr(char *buf, int i, int tetromins, int dot);
void	ft_check_near(char *buf, int i);

void	ft_make_diffirent(char **tetris, int i, int j);
int		ft_count_figures(char *str);
int		ft_first_not_dot(char *str);
int		ft_size(char **str);
void	error(void);

#endif
