/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minusmissing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:21:05 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 15:26:10 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define IF() (res->zero == 0 || res->press > 0)

static void	minus_next(t_arg *res, intmax_t len, intmax_t num)
{
	if (res->minus == 0 && num < 0)
	{
		if (res->zero > 0 && res->press == -1)
		{
			write(1, "-", 1);
			res->len += 1;
		}
		if (res->press > len)
			res->width -= 1 + res->press;
		else
			res->width -= len + 1;
		res->press == -1 && res->zero > 0 ? writezero(res) : writewidth(res);
		if (res->zero == 0 || res->press > 0)
		{
			write(1, "-", 1);
			res->len += 1;
		}
		res->press -= len;
		writepress(res);
		ft_putnbr_new(num, res);
		res->len += len;
	}
}

static void	min_miss(t_arg *res, intmax_t len)
{
	if (res->zero > 0 && res->press == -1 && res->plus > 0)
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

void		minusmissing(t_arg *res, intmax_t len, intmax_t num)
{
	if (res->minus == 0 && num > 0)
	{
		min_miss(res, len);
		IF() && res->plus > 0 ? res->width -= 1 : 0;
		res->press == -1 && res->zero > 0 ? writezero(res) : writewidth(res);
		IF() && res->plus > 0 ? write(1, "+", 1) : 0;
		res->press -= len;
		writepress(res);
		ft_putnbr_new(num, res);
		res->plus == 0 ? res->len += len : 0;
		res->plus != 0 ? res->len += len + 1 : 0;
	}
	minus_next(res, len, num);
}
