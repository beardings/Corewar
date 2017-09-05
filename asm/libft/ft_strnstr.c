/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:51:30 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/02 15:11:43 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size;

	size = ft_strlen(little);
	if (!(*little))
		return ((char *)big);
	while (len && *big)
	{
		if (len >= size)
		{
			if (!ft_strncmp(big, little, size))
				return ((char *)big);
		}
		else
			return (NULL);
		big++;
		len--;
	}
	return (NULL);
}
