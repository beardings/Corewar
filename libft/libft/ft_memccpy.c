/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:42:49 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/02 22:46:25 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*pdst;
	char const		*psrc;

	pdst = dst;
	psrc = src;
	if (n == 0)
		return (NULL);
	while (n)
	{
		if (*psrc == c)
		{
			*pdst = *psrc;
			return (++pdst);
		}
		*pdst++ = *psrc++;
		n--;
	}
	return (NULL);
}
