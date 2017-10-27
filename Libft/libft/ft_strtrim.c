/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:56:03 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/02 15:10:22 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	stop;
	char	*str;

	if (!s)
	{
		str = ft_strnew(0);
		return (str);
	}
	start = 0;
	stop = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if ((stop + 1) == start)
	{
		str = ft_strnew(0);
		return (str);
	}
	while (s[stop] == ' ' || s[stop] == '\t' || s[stop] == '\n')
		stop--;
	str = ft_strsub(s, start, stop - start + 1);
	if (!str)
		return (NULL);
	return (str);
}
