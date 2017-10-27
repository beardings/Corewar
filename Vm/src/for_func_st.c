/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_func_st.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 02:12:33 by ngulya            #+#    #+#             */
/*   Updated: 2017/10/28 02:33:38 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
#include "../includes/op.h"

void		one_sti(t_players *player, t_byte *map, int r12, int r)
{
	unsigned int	r3;

	r3 = (unsigned int)r;
	map[(MEM_SIZE + (player->pos + ((r12) % IDX_MOD)))\
		% MEM_SIZE] = r3 / 0x1000000;
	map[(MEM_SIZE + (player->pos + ((r12) % IDX_MOD +\
		1))) % MEM_SIZE] = (r3 / 0x10000) & 0xFF;
	map[(MEM_SIZE + (player->pos + ((r12) % IDX_MOD +\
		2))) % MEM_SIZE] = (r3 / 0x100) & 0xFF;
	map[(MEM_SIZE + (player->pos + ((r12) % IDX_MOD +\
		3))) % MEM_SIZE] = r3 % 0x100;
	player->st = (MEM_SIZE + (player->pos + ((r12) %\
		IDX_MOD))) % MEM_SIZE;
}

void		two_sti(t_players *player, t_byte *map, int r12, int r)
{
	unsigned int	r3;

	r3 = (unsigned int)r;
	map[(player->pos + ((r12) % IDX_MOD)) %\
		MEM_SIZE] = r3 / 0x1000000;
	map[(player->pos + ((r12) % IDX_MOD + 1)) %\
		MEM_SIZE] = (r3 / 0x10000) & 0xFF;
	map[(player->pos + ((r12) % IDX_MOD + 2)) %\
		MEM_SIZE] = (r3 / 0x100) & 0xFF;
	map[(player->pos + ((r12) % IDX_MOD + 3)) %\
		MEM_SIZE] = r3 % 0x100;
	player->st = (player->pos + ((r12) % IDX_MOD)) %\
	MEM_SIZE;
}
