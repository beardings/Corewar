/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numnull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:00:14 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 15:13:02 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define OR() (res->press == 0 && res->zero == 1)

static void	numnull_n(t_arg *res)
{
	if (res->plus > 0)
	{
		write(1, "+", 1);
		res->width -= 1;
	}
	if (res->press > 1)
	{
		res->space > 0 ? res->width -= res->press + 1 : 0;
		res->space == 0 ? res->width -= res->press : 0;
	}
	else
	{
		res->space == 0 && res->press != 0 ? res->width -= 1 : 0;
		res->space > 0 ? res->width -= 1 + 1 : 0;
	}
	if (res->space > 0)
	{
		write(1, " ", 1);
		res->len++;
	}
	if (res->press > 0 && res->width < 1)
	{
		res->press -= 1;
		writepress(res);
	}
}

static void	numnull_next(t_arg *res)
{
	numnull_n(res);
	if (res->width > 0 && (res->zero == 0 || OR()))
	{
		writewidth(res);
		res->width -= res->width;
	}
	res->press == -1 && res->zero > 0 ? writezero(res) : 0;
	res->press == 0 && res->zero == 0 ? writewidth(res) : 0;
	res->press == -1 && res->zero == 0 ? writewidth(res) : 0;
	res->press > 0 && res->width > 0 ? writewidth(res) : 0;
	res->plus == 0 && res->press != 0 ? res->len += 1 : 0;
	if (res->press > 0 && res->zero > 0)
	{
		res->press -= 1;
		writepress(res);
	}
	res->plus != 0 ? res->len += 1 + 1 : 0;
	res->press != 0 ? ft_putnbr(0) : 0;
}

int			numnull(t_arg *res)
{
	if (res->minus > 0)
	{
		if (res->space > 0)
		{
			write(1, " ", 1);
			res->width -= 1;
			res->len++;
		}
		if (res->plus > 0)
		{
			write(1, "+", 1);
			res->width -= 1;
			res->len++;
		}
		res->press > 1 ? res->width -= res->press : 0;
		res->press < 1 ? res->width -= 1 : 0;
		res->press -= 1;
		writepress(res);
		ft_putnbr(0);
		res->len += 1;
		res->press > 1 && res->zero > 0 ? writezero(res) : writewidth(res);
	}
	else
		numnull_next(res);
	return (0);
}
