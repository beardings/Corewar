/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_mod_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:33:12 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 17:53:07 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ORTYPE() (res->type == 'x' || res->type == 'o' || res->type == 'u')
#define PRHFTP() printhesh(res), ft_putstr(tmp)
#define DO() writewidth(res), res->len += len
#define IF() !(res->zero) && !(res->minus) && !(res->hesh)
#define IF2() (res->zero) && !(res->minus) && !(res->hesh)
#define IF3() !(res->zero) && (res->minus) && !(res->hesh)
#define IF4() !(res->zero) && (res->minus) && (res->hesh)
#define RESU() res->type != 'u' && res->type != 'U'

static void	cast_m(char *tmp, int len, t_arg *res)
{
	if (res->press > len)
	{
		res->type == 'p' && tmp[0] == '0' ? res->width -= 2 : 0;
		res->type == 'p' && tmp[0] != '0' ? res->width -= len + 2 : 0;
		res->width -= res->press;
		writewidth(res);
		res->width = res->press - len;
		res->type == 'p' ? preox(res) : 0;
		writezero(res);
		ft_putstr(tmp);
		res->len += len;
	}
	else
	{
		res->type == 'p' ? res->width -= len + 2 : 0;
		res->type != 'p' ? res->width -= len : 0;
		writewidth(res);
		res->type == 'p' ? preox(res) : 0;
		ft_putstr(tmp);
		res->len += len;
	}
}

static void	cast_mm(char *tmp, int len, t_arg *res)
{
	if (res->press > len)
	{
		res->type == 'p' ? preox(res) : 0;
		res->width -= res->press;
		writewidth(res);
		res->width = res->press - len;
		writezero(res);
		ft_putstr(tmp);
		res->len += len;
	}
	else
	{
		res->type == 'p' ? res->width -= len + 2 : 0;
		res->type != 'p' ? res->width -= len : 0;
		if ((tmp[0] == '0' && tmp[1] == '\0') && ORTYPE())
			write(1, " ", 1);
		else
		{
			res->type == 'p' ? preox(res) : 0;
			writezero(res);
			ft_putstr(tmp);
		}
		res->len += len;
	}
}

static void	cast_mmm(char *tmp, int len, t_arg *res)
{
	if (res->press > len)
	{
		res->type == 'p' ? preox(res) : 0;
		res->press -= len;
		writepress(res);
		ft_putstr(tmp);
		res->width -= res->press + len;
		writewidth(res);
		res->len += len;
	}
	else
	{
		res->type == 'p' ? preox(res) : 0;
		ft_putstr(tmp);
		res->type == 'p' ? res->width -= len + 2 : 0;
		res->type != 'p' ? res->width -= len : 0;
		writewidth(res);
		res->len += len;
	}
}

static void	cast_mmmm(char *tmp, int len, t_arg *res)
{
	if (res->press > len)
	{
		res->type == 'p' ? preox(res) : 0;
		printhesh(res);
		if ((res->type == 'x' || res->type == 'X') && res->type != 'p')
			res->press -= len;
		else if (res->type != 'p' && res->type != 'x' && res->type != 'X')
		{
			RESU() ? res->press -= len + res->hesh : 0;
			res->type == 'u' || res->type == 'U' ? res->press -= len : 0;
		}
		writepress(res);
		ft_putstr(tmp);
		res->type != 'p' ? res->width -= res->press + len + res->hesh : 0;
		res->type == 'p' ? res->width -= res->press + len : 0;
		DO();
	}
	else
	{
		res->type == 'p' ? preox(res) : 0;
		PRHFTP();
		res->type != 'p' ? res->width -= len + res->hesh : 0;
		res->type == 'p' ? res->width -= len + 2 : 0;
		DO();
	}
}

int			cast_mod_base(char *tmp, int len, t_arg *res)
{
	if (res->press == -1 && res->zero == 2 && tmp[0] == '0' && tmp[1] == '\0')
	{
		ft_putstr(tmp);
		res->len += len;
	}
	else if (!(res->width) && (res->press) == -1 && IF())
	{
		res->len += len;
		res->type == 'p' ? preox(res) : 0;
		ft_putstr(tmp);
	}
	else if ((res->width) && (res->press) == -1 && IF())
		cast_mod_b(tmp, len, res);
	else if ((res->width) && (res->press) && IF())
		cast_m(tmp, len, res);
	else if ((res->width) && (res->press) && IF2())
		cast_mm(tmp, len, res);
	else if ((res->width) && (res->press) && IF3())
		cast_mmm(tmp, len, res);
	else if ((res->width) && (res->press) && IF4())
		cast_mmmm(tmp, len, res);
	else
		cast_mod_cont(tmp, len, res);
	free(tmp);
	return (0);
}
