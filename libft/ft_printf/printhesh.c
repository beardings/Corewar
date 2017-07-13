/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:54:01 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 14:54:20 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printhesh(t_arg *res)
{
	if (res->type == 'X')
	{
		ft_putnbr(0);
		write(1, "X", 1);
		res->len += 2;
		res->hesh = 2;
	}
	else if (res->type == 'x')
	{
		ft_putnbr(0);
		write(1, "x", 1);
		res->len += 2;
		res->hesh = 2;
	}
	else if (res->type == 'o' || res->type == 'O')
	{
		ft_putnbr(0);
		res->len += 1;
	}
	else if (res->type == 'u' || res->type == 'U')
		res->hesh -= 1;
}
