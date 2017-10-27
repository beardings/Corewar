/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:09:06 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/04 18:19:45 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	size_t		ss;
	const char	*fs;
	const char	*fd;

	ss = size;
	fd = dst;
	fs = src;
	while (*dst != '\0' && ss-- != 0)
		dst++;
	len = dst - fd;
	ss = size - len;
	if (ss-- == 0)
		return (len + ft_strlen(src));
	while (*src != '\0')
	{
		if (ss != 0)
		{
			*dst++ = *src;
			ss--;
		}
		src++;
	}
	*dst = '\0';
	return (len + (src - fs));
}
