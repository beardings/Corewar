/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 13:39:29 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/06 13:39:30 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*ten_hex(long long int i, char *str, int size)
{
	char	*m;
	char	*tmp;
	int		l;

	if (i < 0)
		i = 9223372036854775807 + i + 1;
	l = 0;
	m = (char *)malloc(sizeof(char) * (size + 1));
	*(m + size) = '\0';
	while (l < size)
		m[l++] = '0';
	l--;
	while (i && l >= 0)
	{
		m[l] = HEX[i % 16];
		l--;
		i = i / 16;
	}
	if (!str)
		return (m);
	tmp = ft_strjoin(str, m);
	free(str);
	free(m);
	return (tmp);
}
