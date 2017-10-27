/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writewchar_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 23:21:33 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:51:23 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		write_tn(wchar_t c, t_arg *res)
{
	ft_putchar((char)((c >> 18) + 0xF0));
	ft_putchar((char)(((c >> 12) & 0x3F) + 0x80));
	ft_putchar((char)(((c >> 6) & 0x3F) + 0x80));
	ft_putchar((char)((c & 0x3F) + 0x80));
	res->len += 4;
}

void			writewchar_t(wchar_t c, t_arg *res)
{
	if (c <= 0x7F)
	{
		ft_putchar((char)c);
		res->len += 1;
	}
	else if (c <= 0x7FF)
	{
		ft_putchar((char)((c >> 6) + 0xC0));
		ft_putchar((char)((c & 0x3F) + 0x80));
		res->len += 2;
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((char)((c >> 12) + 0xE0));
		ft_putchar((char)(((c >> 6) & 0x3F) + 0x80));
		ft_putchar((char)((c & 0x3F) + 0x80));
		res->len += 3;
	}
	else if (c <= 0x10FFFF)
		write_tn(c, res);
}
