/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castflag_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:37:43 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:40:10 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ANDPRE() (res->press) == -1

static void	cast_nnnn(int i, t_arg *res, char *tmp)
{
	tmp == NULL ? res->width = res->width - 6 : 0;
	res->width -= i;
	writezero(res);
	(ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstr(tmp);
	res->len += i;
}

static void	cast_nnn(int i, t_arg *res, char *tmp)
{
	tmp == NULL ? res->width = res->width - 6 : 0;
	res->width -= i;
	ft_putstr(tmp);
	writezero(res);
	res->len += i;
}

static void	cast_nn(int i, t_arg *res, char *tmp)
{
	tmp == NULL ? res->width = res->width - 6 : 0;
	res->width -= i;
	(ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstr(tmp);
	writewidth(res);
	res->len += i;
}

static void	cast_n(int i, t_arg *res, char *tmp)
{
	tmp == NULL ? res->width = res->width - 6 : 0;
	if (res->width > i)
	{
		res->width -= i;
		writewidth(res);
	}
	if ((ft_null(tmp, res, 6)) != 1)
	{
		ft_putstr(tmp);
		res->len += i;
	}
}

int			castflag_s(t_arg *res)
{
	char	*tmp;
	int		i;

	tmp = (char *)res->tmp;
	i = 0;
	tmp != NULL ? i = (int)ft_strlen(tmp) : 0;
	if (!(res->width) && !(res->minus) && !(res->zero) && (res->press) == -1)
	{
		(ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstr(tmp);
		res->len += i;
	}
	else if ((res->width) && !(res->minus) && !(res->zero) && ANDPRE())
		cast_n(i, res, tmp);
	else if ((res->width) && (res->minus) && !(res->zero) && (res->press) == -1)
		cast_nn(i, res, tmp);
	else if ((res->width) && (res->minus) && (res->zero) && (res->press) == -1)
		cast_nnn(i, res, tmp);
	else if ((res->width) && !(res->minus) && (res->zero) && (res->press) == -1)
		cast_nnnn(i, res, tmp);
	else if (res->press)
		castpress_s(res, i, tmp);
	else
		cast_nnnnn(i, res, tmp);
	return (0);
}
