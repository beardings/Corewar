/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:34:48 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/01 18:24:47 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *sss;

	sss = (char *)s;
	while (*sss)
		sss++;
	if (*sss == c)
		return (sss);
	sss--;
	while (*sss)
	{
		if (*sss == c)
			return (sss);
		sss--;
	}
	return (NULL);
}
