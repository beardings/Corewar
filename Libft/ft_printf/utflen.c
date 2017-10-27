/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utflen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:58:41 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 13:58:49 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		utflen(wchar_t *tmp)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (tmp[k] != '\0')
	{
		if (tmp[k] <= 0x7F)
			i++;
		else if (tmp[k] <= 0x7FF)
			i += 2;
		else if (tmp[k] <= 0xFFFF)
			i += 3;
		else if (tmp[k] <= 0x10FFFF)
			i += 4;
		k++;
	}
	return (i);
}
