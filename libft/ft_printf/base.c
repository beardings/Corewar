/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 23:07:39 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/03 23:07:55 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*base(t_arg *res, uintmax_t mun)
{
	char	*tmp;

	tmp = NULL;
	if (res->type == 'o' || res->type == 'O')
		tmp = ft_itoa_base(mun, 8, res);
	if (res->type == 'u' || res->type == 'U')
		tmp = ft_itoa_base(mun, 10, res);
	if (res->type == 'x' || res->type == 'X' || res->type == 'p')
		tmp = ft_itoa_base(mun, 16, res);
	return (tmp);
}
