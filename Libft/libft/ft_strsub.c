/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:10:53 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/02 15:21:19 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;

	res = NULL;
	if (s && len)
	{
		res = (char *)malloc(len + 1);
		if (res != NULL)
		{
			ft_strncpy(res, s + start, len + 1);
			*(res + len) = '\0';
			return (res);
		}
	}
	return (NULL);
}
