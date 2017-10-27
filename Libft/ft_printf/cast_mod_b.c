/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_mod_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:32:13 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 17:32:42 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cast_mod_b(char *tmp, int len, t_arg *res)
{
	res->type == 'p' ? res->width -= len + 2 : 0;
	res->type != 'p' ? res->width -= len : 0;
	writewidth(res);
	res->type == 'p' ? preox(res) : 0;
	ft_putstr(tmp);
	res->len += len;
}
