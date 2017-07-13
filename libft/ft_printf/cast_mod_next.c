/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_mod_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:50:29 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/05 16:57:26 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define NOTU() res->type != 'u' && res->type != 'U'
#define FTPL() ft_putstr(tmp), res->len += len
#define REWR() res->width -= res->press, writewidth(res)

static void	cast_mod_nextt(char *tmp, int len, t_arg *res)
{
	if (res->type != 'o' && res->type != 'O' && NOTU())
		res->width -= len + 2;
	else if (res->type != 'x' && res->type != 'X' && res->type != 'p')
	{
		NOTU() ? res->width -= len + res->hesh : 0;
		res->type == 'u' || res->type == 'U' ? res->width -= len : 0;
	}
	writewidth(res);
	res->type == 'p' ? preox(res) : 0;
	printhesh(res);
	ft_putstr(tmp);
	res->len += len;
}

void		cast_mod_next(char *tmp, int len, t_arg *res)
{
	if (res->press > len)
	{
		res->type == 'p' ? preox(res) : 0;
		if (res->type != 'o' && res->type != 'O' && NOTU())
			res->width += res->hesh + 1;
		if (res->type != 'x' && res->type != 'X' && res->type != 'p')
		{
			REWR();
		}
		printhesh(res);
		if ((res->type == 'x' || res->type == 'X') && res->type != 'p')
		{
			res->press -= len;
			writepress(res);
		}
		else if (res->type != 'x' && res->type != 'X' && res->type != 'p')
		{
			NOTU() ? res->press -= len + res->hesh : 0;
			res->type == 'u' || res->type == 'U' ? res->press -= len : 0;
			writepress(res);
		}
		FTPL();
	}
	else
		cast_mod_nextt(tmp, len, res);
}
