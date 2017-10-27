/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castflag_bigc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:49:02 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/05 21:05:06 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	utflenl(wchar_t c)
{
	int		i;

	i = 0;
	if (c <= 0x7F)
		i++;
	else if (c <= 0x7FF)
		i += 2;
	else if (c <= 0xFFFF)
		i += 3;
	else if (c <= 0x10FFFF)
		i += 4;
	return (i);
}

static void	cast_cn(wchar_t c, int i, t_arg *res)
{
	res->width -= i;
	writewidth(res);
	writewchar_t(c, res);
}

void		castflag_bigc(t_arg *res)
{
	wchar_t	c;
	int		i;

	c = (wchar_t)res->tmp;
	i = utflenl(c);
	if (!(res->width) && !(res->minus) && !(res->zero))
		writewchar_t(c, res);
	else if ((res->width) && !(res->minus) && !(res->zero))
		cast_cn(c, i, res);
	else if ((res->width) && (res->minus) && !(res->zero))
	{
		writewchar_t(c, res);
		res->width -= i;
		writewidth(res);
	}
	else if ((res->width) && !(res->minus) && (res->zero))
	{
		res->width -= i;
		writezero(res);
		writewchar_t(c, res);
	}
	else
		writewchar_t(c, res);
}
