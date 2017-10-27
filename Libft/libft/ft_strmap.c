/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:57:33 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/02 14:44:18 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				*ss++ = (*f)(*s++);
				cnt++;
			}
			*ss++ = '\0';
			return (ss - cnt - 1);
		}
	}
	return (NULL);
}
