/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:46:11 by mponomar          #+#    #+#             */
/*   Updated: 2016/11/30 17:58:26 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)dst;
	s2 = (char *)src;
	i = len;
	if (src > dst)
	{
		while (i--)
			*s1++ = *s2++;
	}
	else
	{
		while (len--)
			s1[len] = s2[len];
	}
	return (dst);
}
