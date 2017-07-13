/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:29:38 by mponomar          #+#    #+#             */
/*   Updated: 2016/11/30 19:30:33 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pstr;
	int		len;
	int		cnt;

	cnt = 0;
	len = (int)ft_strlen(s1);
	pstr = (char*)malloc(sizeof(*pstr) * (len + 1));
	if (!pstr)
		return (0);
	ft_bzero(pstr, ft_strlen(pstr));
	while (*s1)
	{
		*pstr++ = *s1++;
		cnt++;
	}
	*pstr = '\0';
	pstr -= cnt;
	return (pstr);
}
