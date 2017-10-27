/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:54:22 by ngulya            #+#    #+#             */
/*   Updated: 2016/11/25 17:03:58 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*new;

	new = dst;
	while (*src && len)
	{
		*new++ = *src++;
		len--;
	}
	while (len--)
		*new++ = '\0';
	return (dst);
}
