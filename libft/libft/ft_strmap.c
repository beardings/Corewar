/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:38:33 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/12 16:24:15 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	char	*pp;

	if (s && f)
	{
		if ((p = ft_strnew(ft_strlen(s))))
		{
			pp = p;
			while (*s)
			{
				*p++ = (*f)(*s);
				s++;
			}
			return (pp);
		}
	}
	return (NULL);
}
