/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_funcs_ld_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:31:13 by ngulya            #+#    #+#             */
/*   Updated: 2017/10/27 19:31:13 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	for_ld_end(byte *map, t_players **player, int posit, int r1)
{
	if (map[((*player)->pos + posit + 1) % MEM_SIZE] \
		< 1 || map[((*player)->pos + posit + 1) % MEM_SIZE] > REG_NUMBER)
	{
		(*player)->pos += posit + 2;
		return ;
	}
	(*player)->reg[map[((*player)->pos + posit + 1) % MEM_SIZE] - 1] = r1;
	(*player)->pos += posit + 2;
	if (r1 == 0)
		(*player)->carry = 1;
	else
		(*player)->carry = 0;
}

int		for_ldi_start(t_players **player, int *posit, byte *map, char **bin)
{
	int		ret;

	ret = -134;
	if (ft_strnstr(*bin, "10", 2))
	{
		ret = get_tdir(2, (*player)->pos + (*posit) + 1, map);
		(*posit) += 2;
	}
	else if (ft_strnstr(*bin, "01", 2))
	{
		ret = get_reg((*player), (*player)->pos + (*posit) + 1, map);
		(*posit)++;
	}
	(*bin) -= 2;
	return (ret);
}

int		for_ldi_peredstart(t_players **p, int *posit, byte *map, char **bin)
{
	int		ret;

	ret = -134;
	if (ft_strnstr(*bin, "11", 2))
	{
		ret = get_indir((*p), 'r', (*p)->pos + (*posit) + 1, map);
		(*posit) += 2;
	}
	else if (ft_strnstr(*bin, "10", 2))
	{
		ret = (short int)get_tdir(2, (*p)->pos + (*posit) + 1, map);
		(*posit) += 2;
	}
	else if (ft_strnstr(*bin, "01", 2))
	{
		ret = get_reg((*p), (*p)->pos + (*posit) + 1, map);
		(*posit)++;
	}
	*bin += 2;
	return (ret);
}

void	mu_obnylyaem(int *r1, int *r2, int *for_r, int *posit)
{
	(*r1) = 0;
	(*r2) = 0;
	(*for_r) = -1;
	(*posit) = 1;
}

int		return_ldi(byte *map, t_players *player, int *posit)
{
	if (map[(player->pos + (*posit) + 1) % MEM_SIZE]\
	< 1 || map[(player->pos + (*posit) + 1) % MEM_SIZE] > REG_NUMBER)
	{
		player->pos += ++(*posit) + 1;
		return (1);
	}
	return (0);
}
