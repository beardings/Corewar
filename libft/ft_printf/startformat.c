/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:00:48 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 14:49:44 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_n(size_t i, const char *format, t_arg *res)
{
	if (format[i] == 'h' && format[i + 1] == 'h' && res->flag <= 1)
	{
		res->flag = 1;
		return (2);
	}
	if (format[i] == 'h' && format[i + 1] != 'h' && res->flag <= 2)
	{
		res->flag = 2;
		res->h++;
		return (1);
	}
	if (format[i] == 'l' && format[i + 1] != 'l' && res->flag <= 3)
	{
		res->flag = 3;
		return (1);
	}
	if (format[i] == 'l' && format[i + 1] == 'l' && res->flag <= 4)
	{
		res->flag = 4;
		return (2);
	}
	return (0);
}

int				checkflags(size_t i, const char *format, t_arg *res)
{
	int			k;

	k = 0;
	k += check_n(i, format, res);
	if (format[i] == 'j' && res->flag <= 5)
	{
		res->flag = 5;
		k++;
	}
	if (format[i] == 'z' && res->flag <= 6)
	{
		res->flag = 6;
		k++;
	}
	if (res->h > 0 && (res->h % 2) > 0)
		res->flag <= 2 ? res->flag = 2 : 0;
	if (res->h > 0 && (res->h % 2) == 0)
		res->flag <= 2 ? res->flag = 1 : 0;
	if (res->flag > 0 && k == 0)
		k++;
	return (res->flag > 0 || k != 0 ? k : 0);
}

static int		checkzmpn(size_t i, const char *format, t_arg *res)
{
	if (format[i] == '#')
	{
		res->hesh = 1;
		return (1);
	}
	if (format[i] == '+')
	{
		res->plus = 1;
		return (1);
	}
	if (format[i] == '0')
	{
		res->zero = 1;
		return (1);
	}
	if (format[i] == '-')
	{
		res->minus = 1;
		return (1);
	}
	return (0);
}

int				checkhzmp(size_t i, const char *format, t_arg *res)
{
	int			k;

	k = 0;
	k += checkzmpn(i, format, res);
	if (format[i] == ' ' && format[i] != '\t')
	{
		res->space = 1;
		k++;
	}
	if (format[i] == '.')
	{
		res->press = 0;
		k = 1;
	}
	if (format[i] == '.' && (format[i + 1] > 48 && format[i + 1] < 58))
	{
		res->press = number(format, i + 1);
		k = 1 + ft_lenint(res->press);
	}
	if ((format[i] > 48 && format[i] < 58) && format[i - 1] != '.')
	{
		res->width = number(format, i);
		k = ft_lenint(res->width);
	}
	return (k > 0 ? k : 0);
}

size_t			startformat(size_t i, const char *format, t_arg *res)
{
	size_t		k;

	while (format[i] != '%' && format[i] != '\0')
	{
		k = 0;
		if (!(checktype(i, format, res)))
			if (!(k = (size_t)checkhzmp(i, format, res)))
				if (!(k = (size_t)checkflags(i, format, res)))
					return (i);
		k != 0 ? i += k : i++;
		if (res->type != '\0')
			return (i);
	}
	return (i);
}
