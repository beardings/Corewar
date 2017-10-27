/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:55:17 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:55:26 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				checktype(size_t i, const char *format, t_arg *res)
{
	char		*types;
	size_t		k;

	k = 0;
	types = "sSpdDioOuUxXcC";
	while (types[k] != '\0')
	{
		if (format[i] == types[k])
		{
			res->type = format[i];
			return (1);
		}
		k++;
	}
	return (0);
}
