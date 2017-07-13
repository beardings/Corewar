/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hz.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:41:30 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/12 18:24:14 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_hz(char **ptr, int word, char const *s, char c)
{
	int				begin;
	int				i;
	int				d;

	i = 0;
	d = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && d < word)
	{
		if (s[i] != c)
		{
			begin = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			ptr[d] = ft_strsub(s, begin, i - begin);
			d++;
		}
		i++;
	}
	ptr[word] = 0;
	return (ptr);
}
