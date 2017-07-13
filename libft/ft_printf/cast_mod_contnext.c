/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_mod_contnext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:26:35 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/05 17:27:52 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define NOTMHE() !(res->minus) && !(res->hesh)

static void	cast_mod_conext(char *tmp, int len, t_arg *res)
{
	if (res->type != 'u' && res->type != 'U')
	{
		printhesh(res);
		res->width -= res->hesh;
	}
	if (tmp[0] != '0')
	{
		ft_putstr(tmp);
		res->len += len;
	}
	res->width -= len;
	writewidth(res);
}

static void	cast_mod_conextt(char *tmp, int len, t_arg *res)
{
	res->type == 'p' ? preox(res) : 0;
	res->zero > 0 ? writezero(res) : writewidth(res);
	if (tmp[0] != '0')
	{
		ft_putstr(tmp);
		res->len += len;
	}
}

void		cast_mod_contnext(char *tmp, int len, t_arg *res)
{
	if ((res->width) && (res->press) == 0 && (res->zero) && NOTMHE())
	{
		res->type == 'p' ? preox(res) : 0;
		writewidth(res);
		if (tmp[0] != '0')
		{
			ft_putstr(tmp);
			res->len += len;
		}
	}
	else if (!(res->width) && (res->press) == 0 && NOTMHE())
		cast_mod_conextt(tmp, len, res);
	else if ((res->width) && (res->press) == 0 && (res->minus) && (res->hesh))
		cast_mod_conext(tmp, len, res);
	else if ((res->width) && (res->press) == 0 && (res->minus) && !(res->hesh))
	{
		if (tmp[0] != '0')
		{
			ft_putstr(tmp);
			res->len += len;
		}
		res->width -= len;
		writewidth(res);
	}
}
