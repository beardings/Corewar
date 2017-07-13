/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:52:34 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/12 16:42:59 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char		*f;

	if (!s || !(f = ft_strdup(s)))
		return (NULL);
	s = f;
	while (*f)
		f++;
	while (ft_spacetrim(*s))
		s++;
	while (ft_spacetrim(*f) || (*f == '\0'))
		f--;
	*++f = '\0';
	return (ft_strdup(s));
}
