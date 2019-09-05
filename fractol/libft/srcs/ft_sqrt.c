/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:14:35 by rbirov            #+#    #+#             */
/*   Updated: 2018/11/29 13:41:53 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int index;

	index = 1;
	if (nb <= 0)
		return (0);
	while (index * index < nb)
		index++;
	if (nb % index == 0)
		return (index);
	else
		return (0);
}
