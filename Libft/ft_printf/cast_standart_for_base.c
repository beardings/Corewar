/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_standart_for_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:50:14 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:54:25 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		cast_standart_for_base(t_arg *res)
{
	char	*tmp;
	int		len;

	tmp = cast_mod(res);
	len = (int)ft_strlen(tmp);
	cast_mod_base(tmp, len, res);
}
