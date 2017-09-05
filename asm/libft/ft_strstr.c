/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:58:39 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/02 14:46:05 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	lenl;

	lenl = ft_strlen(little);
	if (!(*little))
		return ((char *)big);
	while (*big)
	{
		if (*big == *little
			&& (ft_strncmp((char *)big, (char *)little, lenl) == 0))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
