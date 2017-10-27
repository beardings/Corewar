/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:33:10 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:52:48 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_newsize(char const *s, char c)
{
	int		word;
	int		count;

	count = 0;
	word = 0;
	while (s[count] == c && s[count] != '\0')
		count++;
	while (s[count] != '\0')
	{
		if (s[count] != c && (s[count + 1] == c || s[count + 1] == '\0'))
		{
			count++;
			word++;
		}
		count++;
	}
	return (word);
}
