/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_oppcode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:53:19 by liabanzh          #+#    #+#             */
/*   Updated: 2017/10/23 19:53:20 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 4},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 4},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 4},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, 4},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 4},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 4},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 4},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 2},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 2},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 2},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 4},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 2},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 4}
};

int		check_reg(int posit, byte *map)
{
	if (map[posit % MEM_SIZE] >= 1 && map[posit % MEM_SIZE] <= REG_NUMBER)
		return (1);
	else
		return (0);
}

int		get_bit(byte curr_byte, int n)
{
	if (n < 1 || n > 8)
		return (0);
	return (curr_byte >> (n - 1) && 1);
}

int		check_posit(int oppcode, t_players *player)
{
	if (oppcode == 1)
		return (1);
	else if (oppcode != 0)
		return ((oppcode == 3) ? 2 : g_op_tab[player->curr_com - 1].label_size);
	else
		return (0);
}

int		for_check_opcode(t_players *pl, byte *m, int *p, int *o)
{
	int		ok;

	ok = -134;
	if (g_op_tab[pl->curr_com - 1].arguments > 1)
	{
		if (((*o) >> 4 & 3) == 0 || get_bit(g_op_tab[pl->curr_com - 1].r_d_i[1]\
			, (*o) >> 4 & 3) == 0 || (((*o) >> 4 & 3) == 1 \
			&& check_reg(pl->pos + (*p) + 1, m) == 0))
			ok = 0;
		(*p) += check_posit((*o) >> 4 & 3, pl);
	}
	if (g_op_tab[pl->curr_com - 1].arguments == 3)
	{
		if (((*o) >> 2 & 3) == 0)
			ok = 0;
		else if (get_bit(g_op_tab[pl->curr_com - 1].r_d_i[2]\
			, (*o) >> 2 & 3) == 0)
			ok = 0;
		else if (((*o) >> 2 & 3) == 1 && check_reg(pl->pos + (*p) + 1, m) == 0)
			ok = 0;
		(*p) += check_posit((*o) >> 2 & 3, pl);
	}
	return (ok);
}

int		check_oppcode(t_players *player, byte *map)
{
	int		posit;
	int		oppcode;
	int		ok;
	int		fook;

	posit = 1;
	ok = 1;
	oppcode = map[(player->pos + 1) % MEM_SIZE];
	if ((oppcode >> 6) == 0)
		ok = 0;
	else if (get_bit(g_op_tab[player->curr_com - 1].r_d_i[0]\
		, oppcode >> 6) == 0)
		ok = 0;
	else if ((oppcode >> 6) == 1 && check_reg(player->pos +\
	posit + 1, map) == 0)
		ok = 0;
	posit += check_posit(oppcode >> 6, player);
	fook = for_check_opcode(player, map, &posit, &oppcode);
	ok = fook == -134 ? ok : fook;
	if (ok == 0)
	{
		player->pos += posit + 1;
		return (0);
	}
	return (1);
}
