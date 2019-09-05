/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:25:40 by rbirov            #+#    #+#             */
/*   Updated: 2018/11/29 13:41:27 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int n, int power)
{
	int	result;

	if (n)
	{
		result = 1;
		if (power < 0)
			return (0);
		if (power == 0)
			return (1);
		while (power > 0)
		{
			result *= n;
			power--;
		}
		return (result);
	}
	return (0);
}
