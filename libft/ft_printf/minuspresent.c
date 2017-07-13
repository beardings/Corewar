/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minuspresent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:16:45 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 15:20:02 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		minus_pre(t_arg *res, intmax_t len, intmax_t num)
{
	if (res->minus > 0 && num < 0)
	{
		write(1, "-", 1);
		res->len += 1;
		if (res->press > len)
			res->width -= 1 + res->press;
		else
			res->width -= len + 1;
		res->press -= len;
		writepress(res);
		ft_putnbr_new(num, res);
		res->press > len && res->zero > 0 ? writezero(res) : writewidth(res);
		res->len += len;
	}
}

static void		minus_pr(t_arg *res, intmax_t len)
{
	if (res->plus > 0)
	{
		write(1, "+", 1);
		res->width -= 1;
	}
	if (res->press > len)
	{
		res->space > 0 ? res->width -= res->press + 1 : 0;
		res->space == 0 ? res->width -= res->press : 0;
	}
	else
	{
		res->space == 0 ? res->width -= len : 0;
		res->space > 0 ? res->width -= len + 1 : 0;
	}
	if (res->space > 0)
	{
		write(1, " ", 1);
		res->len++;
	}
}

void			minuspresent(t_arg *res, intmax_t len, intmax_t num)
{
	if (res->minus > 0 && num > 0)
	{
		minus_pr(res, len);
		res->press -= len;
		writepress(res);
		ft_putnbr_new(num, res);
		res->press == -1 ? writezero(res) : writewidth(res);
		res->plus == 0 ? res->len += len : 0;
		res->plus != 0 ? res->len += len + 1 : 0;
	}
	minus_pre(res, len, num);
}
