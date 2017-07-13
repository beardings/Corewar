/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upperarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:59:30 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/05 20:54:53 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	upperarg(t_arg *res)
{
	if (res->minus > 0 && res->zero > 0)
		res->zero = 0;
	if (res->plus > 0 && res->space > 0)
		res->space = 0;
	if (res->type == 's' && res->flag == 3)
		res->type = 'S';
	if (res->type == 'd' && res->flag == 3)
		res->type = 'D';
	if (res->type == 'c' && res->flag == 3)
		res->type = 'C';
}
