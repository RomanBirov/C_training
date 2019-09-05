/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msydor <msydor@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:15:50 by msydor            #+#    #+#             */
/*   Updated: 2018/11/07 12:15:57 by msydor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_revputstr(char *s)
{
	long int i;

	i = ft_strlen(s);
	while (--i >= 0)
		ft_putchar(s[i]);
	ft_putchar('\n');
}
