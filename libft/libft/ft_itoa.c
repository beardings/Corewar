/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:08:40 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/03 20:48:39 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa(int n)
{
	int				len;
	unsigned int	num;
	char			*str;

	len = 0;
	len = ft_lenint(n);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (0);
	str[len--] = '\0';
	num = ft_signint(n);
	while (len >= 0)
	{
		str[len--] = num % 10 + 48;
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
