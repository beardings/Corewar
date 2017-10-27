/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castflag_bigs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:42:03 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:48:01 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ANDPRE() (res->press) == -1

static int	lenwchar(wchar_t *tmp)
{
	int i;

	i = 0;
	while (tmp[i] != '\0')
		i++;
	return (i);
}

static void	cast_sn(wchar_t *tmp, int i, int len, t_arg *res)
{
	tmp == NULL ? res->width = res->width - 6 : 0;
	if (res->width < len)
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
	else
	{
		res->width -= len;
		writewidth(res);
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
		res->len = res->width + len;
	}
}

static void	cast_snn(wchar_t *tmp, int i, int len, t_arg *res)
{
	tmp == NULL ? res->width = res->width - 6 : 0;
	if (res->width < len)
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
	else
	{
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
		res->width -= len;
		writewidth(res);
		res->len = res->width + len;
	}
}

static void	cast_snnn(wchar_t *tmp, int i, int len, t_arg *res)
{
	tmp == NULL ? res->width = res->width - 6 : 0;
	if (res->width < len)
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
	else
	{
		res->width -= len;
		writezero(res);
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
		res->len = res->width + len;
	}
}

int			castflag_bigs(t_arg *res)
{
	wchar_t	*tmp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	tmp = (wchar_t *)res->tmp;
	tmp != NULL ? i = lenwchar(tmp) : 0;
	tmp != NULL ? len = utflen(tmp) : 0;
	if (!(res->width) && !(res->minus) && !(res->zero) && (res->press) == -1)
	{
		if ((ft_null((char *)tmp, res, 6)) != 1)
			dowchar_t(tmp, res, i);
	}
	else if ((res->width) && !(res->minus) && !(res->zero) && ANDPRE())
		cast_sn(tmp, i, len, res);
	else if ((res->width) && (res->minus) && !(res->zero) && (res->press) == -1)
		cast_snn(tmp, i, len, res);
	else if ((res->width) && !(res->minus) && (res->zero) && (res->press) == -1)
		cast_snnn(tmp, i, len, res);
	else if (res->press > -1)
		castpress_bigs(res, i, tmp, len);
	else
		(ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
	return (0);
}
