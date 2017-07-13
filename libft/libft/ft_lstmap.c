/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:41:36 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/08 22:20:29 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*n;

	if (lst == '\0')
		return (NULL);
	n = f(lst);
	ptr = n;
	while ((lst = lst->next))
	{
		ptr->next = f(lst);
		ptr = ptr->next;
	}
	return (n);
}
