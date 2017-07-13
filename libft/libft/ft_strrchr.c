/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:22:33 by mponomar          #+#    #+#             */
/*   Updated: 2016/11/30 16:44:45 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	if (ft_strchr(s, c))
	{
		i = ft_strlen(s);
		while (s[i] != c)
			i--;
		return ((char *)s + i);
	}
	else
		return (0);
}
