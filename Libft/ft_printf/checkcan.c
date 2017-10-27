/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:19:38 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:19:51 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_t(wchar_t c, t_arg *res)
{
	if (c <= 0x7F && res->press >= 1)
		return (1);
	else if (c <= 0x7FF && res->press >= 2)
		return (2);
	else if (c <= 0xFFFF && res->press >= 3)
		return (3);
	else if (c <= 0x10FFFF && res->press >= 4)
		return (4);
	return (0);
}

int			checkcan(wchar_t *tmp, t_arg *res)
{
	int i;
	int k;
	int z;

	i = 0;
	k = 0;
	z = 0;
	while (tmp[i] != '\0')
	{
		if ((z = (write_t(tmp[i], res))) > 0)
		{
			k += z;
			res->press -= z;
		}
		else
			break ;
		i++;
	}
	res->press += k;
	return (k);
}
