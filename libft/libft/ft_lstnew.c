/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:03:12 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/08 17:30:49 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;

	if ((temp = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	else
	{
		temp->content = ft_memalloc(content_size);
		temp->content = ft_memcpy(temp->content, content, content_size);
		temp->content_size = content_size;
		temp->next = NULL;
	}
	return (temp);
}
