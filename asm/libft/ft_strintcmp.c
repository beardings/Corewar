/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strintcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 14:59:00 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/04 14:59:01 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strintcmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 <= *s2++ && n--)
		if (*s1++ == '\0' || !n)
			return (0);
	s2--;
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int		max_int(char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = line;
	if (*line == '-')
		return (1);
	while (*line && *line >= '0' && *line <= '9')
	{
		i++;
		line++;
	}
	if (*line)
		return (1);
	if (i < 10)
		return (0);
	if (i > 10 || ft_strintcmp(tmp, "2147483647", i) > 0)
		return (1);
	return (0);
}
