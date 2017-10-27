/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdosym.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:56:46 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/01 20:30:51 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdosym(const char *s, char c)
{
	size_t	cc;
	char	*res;

	cc = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *s)
	{
		cc++;
		s++;
	}
	res = ft_strnew(cc);
	res = ft_strncpy(res, s - cc, cc);
	return (res);
}
