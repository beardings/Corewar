/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castpress_bigs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:25:12 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:36:50 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define RESMIN() res->width -= len, writewidth(res)

static void	cast_bigs(t_arg *res, int i, wchar_t *tmp, int len)
{
	if (res->press > len && res->width > len)
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		RESMIN();
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
	}
	else if (res->press > len && res->width < len)
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
	}
	else if (res->press < len && res->width < len)
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		res->width -= (checkcan(tmp, res));
		writewidth(res);
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : otherutf(tmp, res);
	}
	else if (res->press < len && res->width > len)
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		res->width -= (checkcan(tmp, res));
		writewidth(res);
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
	}
}

static void	cast_bigss(t_arg *res, int i, wchar_t *tmp, int len)
{
	if (res->press > len && res->width > len)
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		res->width -= len;
		writezero(res);
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
	}
	else if (res->press > len && res->width < len)
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
	}
	else if (res->press < len && (res->width < len || res->width > len))
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		res->width -= (checkcan(tmp, res));
		writezero(res);
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : otherutf(tmp, res);
	}
}

static void	cast_bigsss(t_arg *res, int i, wchar_t *tmp, int len)
{
	if (res->press > len && res->width > len)
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
		RESMIN();
	}
	else if (res->press > len && res->width < len)
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
	}
	else if (res->press < len && res->width < len)
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : otherutf(tmp, res);
		res->width -= (checkcan(tmp, res));
		writewidth(res);
	}
	else if (res->press < len && res->width > len)
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : otherutf(tmp, res);
		res->width -= (checkcan(tmp, res));
		writewidth(res);
	}
}

static void	cast_bigssss(t_arg *res, int i, wchar_t *tmp, int len)
{
	if (res->width < len)
		writewidth(res);
	else
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
}

void		castpress_bigs(t_arg *res, int i, wchar_t *tmp, int len)
{
	if (!(res->width) && !(res->minus) && !(res->zero) && (res->press) > 0)
	{
		if (res->press > len)
			(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
		else
			otherutf(tmp, res);
	}
	else if ((res->width) && !(res->minus) && !(res->zero) && (res->press) > 0)
		cast_bigs(res, i, tmp, len);
	else if ((res->width) && !(res->minus) && (res->zero) && (res->press) > 0)
		cast_bigss(res, i, tmp, len);
	else if ((res->width) && (res->minus) && !(res->zero) && (res->press) > 0)
		cast_bigsss(res, i, tmp, len);
	else if ((res->width) && !(res->minus) && !(res->zero) && (res->press) == 0)
		cast_bigssss(res, i, tmp, len);
	else if ((res->width) && !(res->minus) && (res->zero) && (res->press) == 0)
		writezero(res);
	else
	{
		if (res->press > len)
			(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
		else
			otherutf(tmp, res);
	}
}
