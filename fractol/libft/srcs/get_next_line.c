/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:50:17 by rbirov            #+#    #+#             */
/*   Updated: 2019/05/22 15:49:41 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	end_of_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		str[i] = '\0';
		return (i);
	}
	else
		return (-1);
}

static char	*join(char *str, char *buf)
{
	size_t	m;
	size_t	k;
	char	*tmp;

	m = 0;
	k = 0;
	if (str != '\0')
		m = ft_strlen(str);
	if (buf != '\0')
		k = ft_strlen(buf);
	if (!(tmp = (char *)malloc(sizeof(char) * (m + k + 1))))
		free(tmp);
	ft_memcpy(tmp, str, m);
	ft_memcpy(tmp + m, buf, k);
	tmp[m + k] = '\0';
	free(str);
	ft_bzero(buf, BUFF_SIZE + 1);
	return (tmp);
}

static int	verif(char **str, char **buf, char **line)
{
	int		last;
	char	*ptr;

	*str = join(*str, *buf);
	last = end_of_line(*str);
	if (last > -1)
	{
		*line = ft_strdup(*str);
		ptr = *str;
		*str = ft_strdup(*str + last + 1);
		free(ptr);
		return (1);
	}
	return (0);
}

void		more(int const fd, char **line, char **str, char *buf)
{
	*line = ft_strdup(str[fd]);
	ft_strdel(&str[fd]);
	free(buf);
}

int			get_next_line(int const fd, char **line)
{
	static char *str[255];
	char		*buf;
	int			total;
	int			ret;

	buf = ft_strnew(BUFF_SIZE);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, buf, 0)) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		total = verif(&str[fd], &buf, line);
		free(buf);
		if (total == 1)
			return (1);
		buf = ft_strnew(BUFF_SIZE);
	}
	if ((total = verif(&str[fd], &buf, line)))
		return (1);
	else if (ft_strlen(str[fd]) > 0)
	{
		more(fd, line, str, buf);
		return (1);
	}
	free(buf);
	return (total);
}
