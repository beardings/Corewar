/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_modnex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:03:03 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/05 17:05:03 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define NOU() res->type != 'u' && res->type != 'U'

static void	cast_modnexx(char *tmp, int len, t_arg *res)
{
	if ((res->type == 'x' || res->type == 'X') && res->type != 'p')
		res->width -= len + res->hesh + 1;
	else if (res->type != 'p')
	{
		NOU() ? res->width -= len + res->hesh : 0;
		res->type == 'u' || res->type == 'U' ? res->width -= len : 0;
	}
	res->type == 'p' ? res->width -= len + 2 : 0;
	writewidth(res);
	printhesh(res);
	res->type == 'p' ? preox(res) : 0;
	ft_putstr(tmp);
	res->len += len;
}

void		cast_modnex(char *tmp, int len, t_arg *res)
{
	if (res->press > len)
	{
		if ((res->type == 'x' || res->type == 'X') && res->type != 'p')
			res->width -= res->press + res->hesh + 1;
		else if (res->type != 'x' && res->type != 'X' && res->type != 'p')
		{
			NOU() ? res->width -= len + res->hesh : 0;
			res->type == 'u' || res->type == 'U' ? res->width -= len : 0;
		}
		res->width > res->press ? writewidth(res) : 0;
		res->type == 'p' ? preox(res) : 0;
		printhesh(res);
		if ((res->type == 'x' || res->type == 'X') && res->type != 'p')
			res->press -= len;
		else if (res->type != 'x' && res->type != 'X' && res->type != 'p')
		{
			NOU() ? res->press -= len + res->hesh : 0;
			res->type == 'u' || res->type == 'U' ? res->press -= len : 0;
		}
		writepress(res);
		ft_putstr(tmp);
		res->len += len;
	}
	else
		cast_modnexx(tmp, len, res);
}
