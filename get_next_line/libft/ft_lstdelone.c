/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 16:00:06 by rbirov            #+#    #+#             */
/*   Updated: 2018/11/10 11:48:44 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!*alst || !del || !alst)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = 0;
}
