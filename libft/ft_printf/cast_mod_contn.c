/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_mod_contn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:15:19 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/05 17:30:27 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define NOTX() res->type != 'x' && res->type != 'X'
#define MINH() !(res->minus) && (res->hesh)
#define MINHE() !(res->minus) && !(res->hesh)
#define TPE() writewidth(res), res->type == 'p' ? preox(res) : 0
#define LENN() ft_putstr(tmp), res->len += len

static void	cast_mod_contnn(char *tmp, int len, t_arg *res)
{
	if (res->press > len)
	{
		res->type == 'p' ? preox(res) : 0;
		tmp[0] != '0' ? printhesh(res) : 0;
		res->type == 'o' || res->type == 'O' ? res->press -= len + res->len : 0;
		res->type == 'x' || res->type == 'X' ? res->press -= len : 0;
		res->type == 'u' || res->type == 'U' ? res->press -= len : 0;
		writepress(res);
		ft_putstr(tmp);
		res->len += len;
	}
	else
	{
		res->type == 'p' ? preox(res) : 0;
		printhesh(res);
		ft_putstr(tmp);
		res->len += len;
	}
}

static void	cast_mod_contnnn(char *tmp, int len, t_arg *res)
{
	res->type == 'p' ? preox(res) : 0;
	printhesh(res);
	if (NOTX() && res->type != 'p' && res->zero == 0)
	{
		res->type == 'o' || res->type == 'O' ? res->width -= len + 1 : 0;
		res->type != 'o' || res->type != 'O' ? res->width -= len : 0;
		writewidth(res);
	}
	else if (NOTX() && res->type != 'p' && res->zero > 0)
	{
		res->type == 'o' || res->type == 'O' ? res->width -= len + 1 : 0;
		res->type != 'o' && res->type != 'O' ? res->width -= len : 0;
		writezero(res);
	}
	else if (res->type != 'p' && (res->type == 'x' || res->type == 'X'))
	{
		res->width -= len + res->hesh;
		writezero(res);
	}
	res->type == 'p' ? res->width -= len + 2 : 0;
	res->type == 'p' ? writezero(res) : 0;
	ft_putstr(tmp);
	res->len += len;
}

static void	cast_mod_contnnnn(char *tmp, int len, t_arg *res)
{
	res->type == 'p' ? preox(res) : 0;
	res->type != 'x' ? printhesh(res) : 0;
	if (tmp[0] != '0')
	{
		ft_putstr(tmp);
		res->len += len;
	}
}

static void	cast_mod_contnnnnn(char *tmp, int len, t_arg *res)
{
	res->type == 'p' ? preox(res) : 0;
	res->type != 'x' ? printhesh(res) : 0;
	if (tmp[0] != '0')
	{
		ft_putstr(tmp);
		res->len += len;
	}
}

void		cast_mod_contn(char *tmp, int len, t_arg *res)
{
	if ((res->width) && (res->press) && !(res->zero) && MINH())
		cast_modnex(tmp, len, res);
	else if ((res->width) && (res->press) > -1 && (res->zero) && MINH())
		cast_mod_next(tmp, len, res);
	else if (!(res->width) && (res->press) && !(res->zero) && MINH())
		cast_mod_contnn(tmp, len, res);
	else if ((res->width) && (res->press) == -1 && (res->zero) && MINH())
		cast_mod_contnnn(tmp, len, res);
	else if (!(res->width) && (res->press) == 0 && !(res->zero) && MINH())
		cast_mod_contnnnn(tmp, len, res);
	else if (!(res->width) && (res->press) == 0 && (res->zero) && MINH())
		cast_mod_contnnnnn(tmp, len, res);
	else if ((res->width) && (res->press) == 0 && !(res->zero) && MINHE())
	{
		res->type == 'p' && tmp[0] == '0' ? res->width -= 2 : 0;
		res->type == 'p' && tmp[0] != '0' ? res->width -= len + 2 : 0;
		res->type != 'p' && tmp[0] != '0' ? res->width -= len : 0;
		TPE();
		if (tmp[0] != '0')
		{
			LENN();
		}
	}
	else
		cast_mod_contnext(tmp, len, res);
}
