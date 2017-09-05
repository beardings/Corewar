/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:43:23 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/02 14:43:24 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ss;
	int		cnt;

	cnt = 0;
	if (s && f)
	{
		ss = (char *)malloc(ft_strlen(s) + 1);
		if (ss != NULL)
		{
			while (*s)
			{
				*ss++ = (*f)(cnt++, *s++);
			}
			*ss++ = '\0';
			return (ss - cnt - 1);
		}
	}
	return (NULL);
}
