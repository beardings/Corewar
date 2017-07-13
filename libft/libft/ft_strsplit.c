/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:11:51 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/12 18:08:16 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char		**ptr;
	int			word;

	if (s == NULL)
		return (NULL);
	word = ft_newsize(s, c);
	ptr = (char **)malloc((word + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	ptr = ft_hz(ptr, word, s, c);
	return (ptr);
}
