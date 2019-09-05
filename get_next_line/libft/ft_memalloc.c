/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:45:56 by rbirov            #+#    #+#             */
/*   Updated: 2018/11/10 10:16:13 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*var;

	if (size != 0)
	{
		var = (void*)malloc(sizeof(void*) * size);
		if (var == 0)
			return (0);
		ft_bzero(var, size);
		return (var);
	}
	return (0);
}
