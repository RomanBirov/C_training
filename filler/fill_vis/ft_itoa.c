/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:19:17 by rbirov            #+#    #+#             */
/*   Updated: 2019/07/29 17:18:02 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_filler.h"

void	neg_nbr(int *sign, int *nbr, int *len)
{
	if (*nbr < 0)
	{
		*sign = -1;
		*nbr *= -1;
		*len += 1;
	}
}

char	*min_nbr(void)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * (11))))
		free(s);
	s = "-2147483648";
	return (s);
}

char	*ft_itoa(int nbr)
{
	char	*s;
	int		sign;
	int		len;
	int		nbrcopy;

	if (nbr == -2147483648)
		return (min_nbr());
	len = 1;
	sign = 0;
	neg_nbr(&sign, &nbr, &len);
	nbrcopy = nbr;
	while (nbrcopy >= 10 && len++)
		nbrcopy /= 10;
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		free(s);
	s[len + 1] = '\0';
	while (len--)
	{
		if ((nbr % 10) < 10)
			s[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (sign < 0)
		s[0] = '-';
	return (s);
}
