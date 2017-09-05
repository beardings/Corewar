/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perebor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:47:37 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/01 20:30:41 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_perebor(const char *s, char c)
{
	size_t	res;

	res = 0;
	while (*s)
	{
		while (*s == c)
		{
			s++;
			if (!*s)
				return (res);
		}
		while (*s != c && *s)
		{
			if (!*s)
				return (res);
			s++;
		}
		res++;
	}
	return (res);
}
