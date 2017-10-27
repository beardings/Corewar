/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castpress_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:21:00 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:23:43 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cast_sn(int i, t_arg *res, char *tmp)
{
	if (res->press > i)
	{
		tmp != NULL && i > 0 ? res->width -= i : 0;
		tmp == NULL && i == 0 ? res->width -= res->press : 0;
		writewidth(res);
		if ((ft_null(tmp, res, res->press)) != 1 || i != 0)
			ft_putstrnew(tmp, i, res);
	}
	else
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		res->width -= res->press;
		writewidth(res);
		(ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstrnew(tmp, res->press, res);
	}
}

static void	cast_snn(int i, t_arg *res, char *tmp)
{
	if (res->press > i)
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		res->width -= i;
		writezero(res);
		(ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstr(tmp);
		res->len += i;
	}
	else
	{
		tmp == NULL ? res->width = res->width - 6 : 0;
		res->width -= res->press;
		writezero(res);
		(ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstrnew(tmp, res->press, res);
	}
}

static void	cast_snnn(int i, t_arg *res, char *tmp)
{
	if (res->press > i)
	{
		res->width -= i;
		ft_putstr(tmp);
		writewidth(res);
		res->len += i;
	}
	else if (res->press < i && res->press != -1)
	{
		res->width -= res->press;
		ft_putstrnew(tmp, res->press, res);
		writewidth(res);
	}
	else if (res->press < i && res->press == -1)
	{
		ft_putstrnew(tmp, res->press, res);
		writewidth(res);
	}
}

static void	cast_snnnn(int i, t_arg *res, char *tmp)
{
	if (res->press > i)
	{
		res->width -= i;
		writezero(res);
		ft_putstr(tmp);
		res->len += i;
	}
	else if (res->press < i)
		ft_putstrnew(tmp, res->press, res);
}

void		castpress_s(t_arg *res, int i, char *tmp)
{
	if (!(res->width) && !(res->minus) && !(res->zero) && (res->press) > 0)
	{
		if (res->press > i)
		{
			(ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstr(tmp);
			res->len += i;
		}
		else
			ft_putstrnew(tmp, res->press, res);
	}
	else if ((res->width) && !(res->minus) && !(res->zero) && (res->press) > 0)
		cast_sn(i, res, tmp);
	else if ((res->width) && !(res->minus) && (res->zero) && (res->press) > 0)
		cast_snn(i, res, tmp);
	else if ((res->width) && (res->minus) && !(res->zero) && (res->press) > 0)
		cast_snnn(i, res, tmp);
	else if (!(res->width) && (res->minus) && !(res->zero) && (res->press) > 0)
		cast_snnnn(i, res, tmp);
}
