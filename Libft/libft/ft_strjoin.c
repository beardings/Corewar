/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:38:37 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/12 16:37:59 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char *s3;

	if (!(s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	s3 = ft_strcpy(s3, s1);
	s3 = ft_strcat(s3, s2);
	return (s3);
}
