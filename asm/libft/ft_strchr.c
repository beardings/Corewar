/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:39:44 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/01 18:24:09 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *sss;

	sss = (char *)s;
	while (*sss)
	{
		if (*sss == c)
		{
			break ;
		}
		sss++;
	}
	if (*sss != c)
		return (NULL);
	else
		return (sss);
}
