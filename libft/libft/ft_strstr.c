/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:36:16 by mponomar          #+#    #+#             */
/*   Updated: 2016/11/30 20:24:28 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *big, const char *little)
{
	const char	*t;
	const char	*reset;

	if (*little == '\0')
		return ((char *)big);
	while (*big)
	{
		reset = little;
		t = big;
		while (*reset == *t && *reset)
		{
			t++;
			reset++;
		}
		if (*reset == '\0')
			return ((char *)big);
		big++;
	}
	return (0);
}
