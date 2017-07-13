/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castflag_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:40:40 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:41:37 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			cast_cnnn(unsigned char c, t_arg *res)
{
	res->width -= 1;
	writezero(res);
	write(1, &c, 1);
	res->len = res->width + 1;
}

static void			cast_cnn(unsigned char c, t_arg *res)
{
	write(1, &c, 1);
	res->width -= 1;
	writewidth(res);
	res->len = res->width + 1;
}

static void			cast_cn(unsigned char c, t_arg *res)
{
	res->width -= 1;
	writewidth(res);
	write(1, &c, 1);
	res->len = res->width + 1;
}

void				castflag_c(t_arg *res)
{
	unsigned char	c;

	c = (unsigned char)res->tmp;
	if (!(res->width) && !(res->minus) && !(res->zero))
	{
		write(1, &c, 1);
		res->len = res->len + 1;
	}
	else if ((res->width) && !(res->minus) && !(res->zero))
		cast_cn(c, res);
	else if ((res->width) && (res->minus) && !(res->zero))
		cast_cnn(c, res);
	else if ((res->width) && !(res->minus) && (res->zero))
		cast_cnnn(c, res);
	else
	{
		write(1, &c, 1);
		res->len = res->len + 1;
	}
}
