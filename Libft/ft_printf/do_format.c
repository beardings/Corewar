/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:09:33 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/05 20:58:12 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			cast_forlenth(t_arg *res)
{
	intmax_t	num;

	upperarg(res);
	if (res->flag == 1 && res->type != 'D')
		num = (char)res->tmp;
	else if (res->flag == 2 && res->type != 'D')
		num = (short)res->tmp;
	else if (res->flag == 3 && res->type != 'D')
		num = (long)res->tmp;
	else if (res->flag == 4 && res->type != 'D')
		num = (long long)res->tmp;
	else if (res->flag == 5 && res->type != 'D')
		num = (intmax_t)res->tmp;
	else if (res->flag == 6 && res->type != 'D')
		num = (size_t)res->tmp;
	else if (res->type == 'd' || res->type == 'i')
		num = (int)res->tmp;
	else
		num = (long)res->tmp;
	finishd(num, res);
}

intmax_t		lenintmax(intmax_t num)
{
	intmax_t	i;

	i = 0;
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

void			ft_putnbr_new(intmax_t n, t_arg *res)
{
	intmax_t	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb < 10 && nb > -1)
		ft_putchar('0' + nb);
	else
	{
		ft_putnbr_new(nb / 10, res);
		ft_putnbr_new(nb % 10, res);
	}
}

void			finishd(intmax_t num, t_arg *res)
{
	intmax_t	len;

	len = lenintmax(num);
	if (res->minus == 0 && num != 0)
		minusmissing(res, len, num);
	if (res->minus != 0 && num != 0)
		minuspresent(res, len, num);
	if (num == 0)
		numnull(res);
}

void			*do_format(t_arg *res)
{
	upperarg(res);
	if (res->type == 'D' || res->type == 'd' || res->type == 'i')
		cast_forlenth(res);
	if (res->type == 'o' || res->type == 'O')
		cast_standart_for_base(res);
	if (res->type == 'u' || res->type == 'U')
		cast_standart_for_base(res);
	if (res->type == 'x' || res->type == 'X' || res->type == 'p')
		cast_standart_for_base(res);
	res->type == 'c' ? castflag_c(res) : 0;
	res->type == 'C' ? castflag_bigc(res) : 0;
	res->type == 's' ? castflag_s(res) : 0;
	res->type == 'S' ? castflag_bigs(res) : 0;
	return (0);
}
