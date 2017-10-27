/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:29:09 by ybelilov          #+#    #+#             */
/*   Updated: 2017/07/07 15:29:11 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int			ft_atoi_unsigned(const char *str)
{
	int						i;
	unsigned long int		res;

	i = 0;
	res = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}
