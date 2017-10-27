/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_func_ld_norm_sec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:34:30 by ngulya            #+#    #+#             */
/*   Updated: 2017/10/27 19:34:31 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

char	*for_blyalld(int *r1, int *posit, t_players *player, byte *map)
{
	*r1 = 0;
	*posit = 1;
	return (get_binary(map, player));
}

int		lldi_hahamf_norm(t_players **player, int *posit, byte *map, char **b)
{
	int	r2;

	r2 = -134;
	if (ft_strnstr((*b), "10", 2))
	{
		r2 = get_tdir(2, (*player)->pos + (*posit) + 1, map);
		(*posit) += 2;
	}
	else if (ft_strnstr((*b), "01", 2))
	{
		r2 = get_reg((*player), (*player)->pos + (*posit) + 1, map);
		(*posit)++;
	}
	(*b) -= 2;
	return (r2);
}
