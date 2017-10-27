/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 23:08:49 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/03 23:15:26 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define A (res->type != 'U' && res->type != 'O' && res->type != 'p')
#define B (res->type == 'o' || res->type == 'u' || res->type == 'X')

char			*cast_mod(t_arg *res)
{
	uintmax_t	mun;
	char		*tmp;

	if (res->flag == 1 && A)
		mun = (unsigned char)res->tmp;
	else if (res->flag == 2 && A)
		mun = (unsigned short)res->tmp;
	else if (res->flag == 3 && res->type != 'p')
		mun = (unsigned long)res->tmp;
	else if (res->flag == 4 && res->type != 'p')
		mun = (unsigned long long)res->tmp;
	else if (res->flag == 5 && res->type != 'p')
		mun = (uintmax_t)res->tmp;
	else if (res->flag == 6 && res->type != 'p')
		mun = (size_t)res->tmp;
	else if (res->type == 'x' || B)
		mun = (unsigned int)res->tmp;
	else
		mun = (unsigned long)res->tmp;
	if (mun == 4294967296 && res->type == 'X' && res->flag < 3)
		mun = 0;
	if (res->type == 'p')
		mun = (uintmax_t)res->tmp;
	tmp = base(res, mun);
	return (tmp);
}
