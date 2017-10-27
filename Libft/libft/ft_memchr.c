/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:21:01 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/04 18:12:15 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;
	unsigned char		cc;

	cc = c;
	ss = s;
	while (n--)
	{
		if (*ss++ == cc)
			return ((void *)(ss - 1));
	}
	return (NULL);
}
