/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:27:34 by mponomar          #+#    #+#             */
/*   Updated: 2016/11/30 19:59:00 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t lendest;
	size_t i;

	lendest = ft_strlen(s1);
	i = 0;
	while (n && s2[i])
	{
		s1[lendest] = s2[i];
		i++;
		n--;
		lendest++;
	}
	s1[lendest] = '\0';
	return (s1);
}
