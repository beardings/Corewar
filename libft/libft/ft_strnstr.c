/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:41:00 by mponomar          #+#    #+#             */
/*   Updated: 2016/11/30 16:46:27 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*t;
	const char	*reset;
	size_t		i;

	if (*little == '\0')
		return ((char *)big);
	while (*big && len)
	{
		i = len;
		reset = little;
		t = big;
		while (*reset == *t && *reset && i)
		{
			t++;
			reset++;
			i--;
		}
		if (*reset == '\0')
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
