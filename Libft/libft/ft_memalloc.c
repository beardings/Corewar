/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 18:33:18 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/07 16:32:54 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *res;

	if ((res = malloc(size)) != NULL)
	{
		ft_bzero(res, size);
		return (res);
	}
	else
		return (NULL);
}
