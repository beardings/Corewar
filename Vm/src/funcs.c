/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:45:43 by liabanzh          #+#    #+#             */
/*   Updated: 2017/07/19 14:45:46 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		get_reg(t_players *player, int posit, t_byte *map)
{
	t_byte	n;

	n = map[posit % MEM_SIZE];
	if (n > REG_NUMBER || n < 1)
		return (0);
	return ((int)player->reg[n - 1]);
}

int		get_tdir(int n, int posit, t_byte *map)
{
	int		res;

	res = 0;
	if (n == 2)
		res = (short int)translate(0, 0, map[posit % MEM_SIZE]\
			, map[(posit + 1) % MEM_SIZE]);
	else if (n == 4)
		res = translate(map[posit % MEM_SIZE], map[(posit + 1) % MEM_SIZE],
				map[(posit + 2) % MEM_SIZE], map[(posit + 3) % MEM_SIZE]);
	return (res);
}

int		get_indir(t_players *player, char flag, int posit, t_byte *map)
{
	int			res;
	short int	arg;
	int			pos;

	res = 0;
	arg = (short int)get_tdir(2, posit, map);
	if (player->pos + arg < 0)
		pos = (MEM_SIZE + (player->pos + (arg % IDX_MOD))) % MEM_SIZE;
	else
		pos = (player->pos + (arg % IDX_MOD)) % MEM_SIZE;
	if (flag == 'r')
		res = (int)translate(map[pos % MEM_SIZE], map[(pos + 1) % MEM_SIZE]\
			, map[(pos + 2) % MEM_SIZE], map[(pos + 3) % MEM_SIZE]);
	else if (flag == 'd')
		res = (short int)arg;
	return (res);
}

void	zjmp(t_players *player, t_byte *map)
{
	short int	jmp;

	jmp = (short int)get_tdir(2, player->pos + 1, map) % IDX_MOD;
	if (player->carry == 1)
	{
		if (jmp + player->pos < 0)
			player->pos = MEM_SIZE + (player->pos + jmp);
		else
			player->pos = (player->pos + jmp) % MEM_SIZE;
	}
	else
		player->pos += 3;
}

void	live(t_players *players, t_byte *map, t_players *player)
{
	int		i;
	int		reg;

	i = 0;
	reg = get_tdir(4, player->pos + 1, map);
	while (players[i].header.prog_name[0] != '\0')
	{
		if (reg == players[i].num)
		{
			players[i].live += 1;
			players[i].last_live = *(players[i].cycles);
			*(players[i].last_herro) = players[i].num;
			player->live_amount += 1;
			player->pos += 5;
			return ;
		}
		i++;
	}
	player->live_amount += 1;
	*(player->last_herro) = player->num;
	(*player).pos += 5;
}
