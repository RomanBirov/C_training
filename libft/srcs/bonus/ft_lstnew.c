/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbirov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:56:17 by rbirov            #+#    #+#             */
/*   Updated: 2018/11/04 16:14:35 by rbirov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(*list))))
		return (0);
	if (content == 0)
	{
		list->content = 0;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = malloc(content_size)))
			return (0);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = 0;
	return (list);
}
