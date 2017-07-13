/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:11:51 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:18:30 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			number(const char *format, size_t i)
{
	int		num;
	char	*tmp;
	int		k;
	size_t	c;

	c = i;
	k = 0;
	while (format[c] > 47 && format[c] < 58)
	{
		k++;
		c++;
	}
	tmp = ft_strnew((size_t)k);
	c = 0;
	while (k)
	{
		tmp[c] = format[i];
		c++;
		i++;
		k--;
	}
	num = ft_atoi(tmp);
	free(tmp);
	return (num);
}

t_arg		*createres(void)
{
	t_arg	*res;

	res = malloc(sizeof(t_arg));
	res->len = 0;
	res->type = '\0';
	res->flag = 0;
	res->space = 0;
	res->minus = 0;
	res->plus = 0;
	res->hesh = 0;
	res->zero = 0;
	res->press = -1;
	res->width = 0;
	res->pro = 0;
	res->h = 0;
	return (res);
}
