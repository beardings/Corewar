/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pozs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:08:00 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/01 20:31:02 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pozs(const char *s1, char *s2, char c)
{
	while (*s1 == c && s1)
		s1++;
	while (*s1 == *s2 && s1 && s2)
	{
		s1++;
		s2++;
	}
	while (*s1 == c && s1)
		s1++;
	return ((char *)s1);
}
