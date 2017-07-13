/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:07:38 by mponomar          #+#    #+#             */
/*   Updated: 2016/11/30 20:06:42 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src,
				size_t size)
{
	const char	*odest;
	const char	*osrc;
	size_t		n;
	size_t		dlen;

	n = size;
	odest = dst;
	osrc = src;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odest;
	n = size - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
