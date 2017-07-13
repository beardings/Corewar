/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:56:37 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/10 17:11:51 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char *p;

	p = (void *)malloc(sizeof(void *) * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, size);
	return (p);
}
