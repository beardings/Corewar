/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:16:15 by ngulya            #+#    #+#             */
/*   Updated: 2016/11/25 18:23:45 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_atoi(const char *str)
{
	long long int	res;
	int				zn;

	res = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	zn = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		res = 10 * res + (*str++ - '0');
	return (zn * res);
}
