/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:28:39 by msydor            #+#    #+#             */
/*   Updated: 2018/10/31 17:28:40 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int out;

	out = n;
	if (out < 0)
	{
		write(fd, "-", 1);
		out *= -1;
	}
	if (out > 9)
		ft_putnbr_fd(out / 10, fd);
	out = (out % 10) + 48;
	write(fd, &out, 1);
}
