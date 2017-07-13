/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:07:13 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:08:29 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			calc(uintmax_t value, char base, char *str, int *i)
{
	char		*look;
	uintmax_t	basse;

	basse = 0;
	look = base == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	base == 'X' || base == 'x' || base == 'p' ? basse = 16 : 0;
	base == 'O' || base == 'o' ? basse = 8 : 0;
	base == 'U' || base == 'u' ? basse = 10 : 0;
	if (value >= basse)
		calc(value / basse, base, str, i);
	str[*i] = look[value % basse];
	(*i)++;
}

char			*ft_itoa_base(uintmax_t value, uintmax_t base, t_arg *res)
{
	char		*str;
	int			i;

	if (2 > base || base > 16 || !(str = (char *)malloc(sizeof(char) * 32)))
		return (NULL);
	ft_bzero(str, 32);
	i = 0;
	calc(value, res->type, str, &i);
	str[i] = '\0';
	return (str);
}
