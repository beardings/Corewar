/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:21:03 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/04 16:43:24 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	list = *alst;
	if (*alst)
	{
		while (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			list = (*alst)->next;
			free(*alst);
			*alst = list;
		}
		*alst = NULL;
	}
}
