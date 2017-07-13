/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writepress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:58:01 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 13:58:09 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	writepress(t_arg *res)
{
	int	i;

	i = 0;
	while (i < res->press && res->press > 0)
	{
		ft_putnbr(0);
		res->len += 1;
		i++;
	}
}