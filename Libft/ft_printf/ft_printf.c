/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:35:29 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:06:03 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	len;
	t_arg	*res;

	len = 0;
	res = createres();
	if (format)
	{
		va_start(arg, format);
		len = searcharg(format, arg, res);
		va_end(arg);
	}
	return ((int)len);
}
