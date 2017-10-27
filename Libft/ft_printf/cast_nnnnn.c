/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_nnnnn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:50:57 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 18:09:47 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cast_nnnnn(int i, t_arg *res, char *tmp)
{
	if (res->press == 0 && res->width > 0)
		res->zero > 0 ? writezero(res) : writewidth(res);
	else
	{
		(ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstr(tmp);
		res->len = res->len + i;
	}
}

void	cast_modd(char *tmp, int len, t_arg *res)
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

void	cast_moddd(char *tmp, int len, t_arg *res)
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
