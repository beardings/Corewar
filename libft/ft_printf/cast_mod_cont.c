/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_mod_cont.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:37:22 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 18:16:55 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define W() (res->width) && (res->press) == -1
#define WW() !(res->width) && (res->press)
#define WWW() !(res->width) && (res->press) == -1
#define BLA() res->type != 'u' && res->type != 'U'

static void	cast_mo(char *tmp, int len, t_arg *res)
{
	if (res->type == 'x' || res->type == 'X')
		res->width -= len + res->hesh + 1;
	else if (res->type != 'p')
	{
		BLA() ? res->width -= len + res->hesh : 0;
		res->type == 'u' || res->type == 'U' ? res->width -= len : 0;
	}
	res->type == 'p' ? res->width -= len + 2 : 0;
	writewidth(res);
	printhesh(res);
	res->type == 'p' ? preox(res) : 0;
	ft_putstr(tmp);
	res->len += len;
}

static void	cast_moo(char *tmp, int len, t_arg *res)
{
	if (res->press > len)
	{
		res->type == 'p' ? preox(res) : 0;
		res->press -= len;
		writepress(res);
		ft_putstr(tmp);
		res->len += len;
	}
	else
	{
		res->type == 'p' ? preox(res) : 0;
		tmp[0] != '0' ? printhesh(res) : 0;
		ft_putstr(tmp);
		res->len += len;
	}
}

static void	cast_mooo(char *tmp, int len, t_arg *res)
{
	if (res->press > len)
	{
		res->type == 'p' ? preox(res) : 0;
		printhesh(res);
		res->press -= len;
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

static void	cast_moooo(char *tmp, int len, t_arg *res)
{
	if (res->press > len)
	{
		res->type == 'p' ? preox(res) : 0;
		res->press -= len;
		writepress(res);
		ft_putstr(tmp);
		res->len += len;
	}
	else
	{
		res->type == 'p' ? preox(res) : 0;
		ft_putstr(tmp);
		res->len += len;
	}
}

void		cast_mod_cont(char *tmp, int len, t_arg *res)
{
	if (WW() && !(res->zero) && !(res->minus) && !(res->hesh))
		cast_modd(tmp, len, res);
	else if (WW() && (res->zero) && !(res->minus) && !(res->hesh))
		cast_moddd(tmp, len, res);
	else if (WW() && !(res->zero) && (res->minus) && !(res->hesh))
		cast_moooo(tmp, len, res);
	else if (WW() && !(res->zero) && (res->minus) && (res->hesh))
		cast_mooo(tmp, len, res);
	else if (WW() && (res->zero) && !(res->minus) && (res->hesh))
		cast_moo(tmp, len, res);
	else if (WWW() && !(res->zero) && !(res->minus) && (res->hesh))
	{
		res->type == 'p' ? preox(res) : 0;
		tmp[0] != '0' ? printhesh(res) : 0;
		ft_putstr(tmp);
		res->len += len;
	}
	else if (W() && !(res->zero) && !(res->minus) && (res->hesh))
		cast_mo(tmp, len, res);
	else
		cast_mod_contn(tmp, len, res);
}
