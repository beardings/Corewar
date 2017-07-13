/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:38:51 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/12 16:26:55 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*p;
	char		*pp;
	int			i;

	if (s && f)
	{
		if ((p = ft_strnew(ft_strlen(s))))
		{
			pp = p;
			i = 0;
			while (*s)
			{
				*p++ = (*f)(i, *s);
				s++;
				i++;
			}
			return (pp);
		}
	}
	return (NULL);
}
