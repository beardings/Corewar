/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:54:21 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/12 16:34:09 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s || (start > (unsigned int)ft_strlen(s)))
		return (NULL);
	else
	{
		dest = (char *)malloc(len + 1);
		dest = ft_strncpy(dest, (s + start), len);
		dest[len] = '\0';
	}
	return (dest);
}
