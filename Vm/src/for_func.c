/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:04:14 by ngulya            #+#    #+#             */
/*   Updated: 2017/10/27 20:04:14 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		translate(byte r1, byte r2, byte r3, byte r4)
{
	return (r1 * 256 * 256 * 256 + r2 * 256 * 256 + r3 * 256 + r4);
}

char	*get_binary(byte *map, t_players *player)
{
	char	*tmp;
	char	*res;
	int		i;

	res = ft_strnew(8);
	tmp = livas_base(map[(player->pos + 1) % MEM_SIZE], 2);
	if (ft_strlen(tmp) < 8)
	{
		i = ft_strlen(tmp);
		while (i)
		{
			res[7 - (ft_strlen(tmp) - i)] = tmp[i - 1];
			i--;
		}
		while (i < 8 - (int)ft_strlen(tmp))
			res[7 - (ft_strlen(tmp) + i++)] = '0';
	}
	else
	{
		free(res);
		return (tmp);
	}
	free(tmp);
	return (res);
}
