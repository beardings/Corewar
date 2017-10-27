/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:22:20 by liabanzh          #+#    #+#             */
/*   Updated: 2017/10/28 01:13:11 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	sub(t_players *player, t_byte *map)
{
	int		r1;
	int		r2;

	if (check_oppcode(player, map) == 0)
		return ;
	r1 = get_reg(player, player->pos + 2, map);
	r2 = get_reg(player, player->pos + 3, map);
	player->reg[map[(player->pos + 4) % MEM_SIZE] - 1] = r1 - r2;
	player->pos += 5;
	if (r1 - r2 == 0)
		player->carry = 1;
	else
		player->carry = 0;
}

void	add(t_players *player, t_byte *map)
{
	int		r1;
	int		r2;

	if (check_oppcode(player, map) == 0)
		return ;
	r1 = get_reg(player, player->pos + 2, map);
	r2 = get_reg(player, player->pos + 3, map);
	player->reg[map[(player->pos + 4) % MEM_SIZE] - 1] = r1 + r2;
	player->pos += 5;
	if (r1 + r2 == 0)
		player->carry = 1;
	else
		player->carry = 0;
}

int		and_xor_dop2(t_players *player, t_byte *map, int *posit, char *opp)
{
	int		r2;

	r2 = 0;
	if (ft_strnstr(opp, "01", 2))
	{
		r2 = get_reg(player, player->pos + *posit + 1, map);
		(*posit)++;
	}
	else if (ft_strnstr(opp, "10", 2))
	{
		r2 = get_tdir(4, player->pos + *posit + 1, map);
		*posit += 4;
	}
	else if (ft_strnstr(opp, "11", 2))
	{
		r2 = get_indir(player, 'r', player->pos + *posit + 1, map);
		*posit += 2;
	}
	return (r2);
}

int		and_xor_dop(t_players *player, t_byte *map, int *posit, char *opp)
{
	int		r1;

	r1 = 0;
	if (ft_strnstr(opp, "01", 2))
	{
		r1 = get_reg(player, player->pos + *posit + 1, map);
		(*posit)++;
	}
	else if (ft_strnstr(opp, "10", 2))
	{
		r1 = get_tdir(4, player->pos + *posit + 1, map);
		*posit += 4;
	}
	else if (ft_strnstr(opp, "11", 2))
	{
		r1 = get_indir(player, 'r', player->pos + *posit + 1, map);
		*posit += 2;
	}
	return (r1);
}

void	and_xor(t_players *player, t_byte *map, char flag)
{
	int		r1;
	int		r2;
	int		p;
	char	*opp;

	p = 1;
	if (check_oppcode(player, map) == 0)
		return ;
	opp = get_binary(map, player);
	r1 = and_xor_dop(player, map, &p, opp);
	r2 = and_xor_dop2(player, map, &p, opp + 2);
	free(opp);
	if ((t_byte)(map[((*player).pos + p + 1) % MEM_SIZE] - 1) > REG_NUMBER - 1)
	{
		player->pos += p + 2;
		return ;
	}
	if (flag == 'a')
		player->reg[map[(player->pos + p + 1) % MEM_SIZE] - 1] = r1 & r2;
	else if (flag == 'o')
		player->reg[map[(player->pos + p + 1) % MEM_SIZE] - 1] = r1 | r2;
	else if (flag == 'x')
		player->reg[map[(player->pos + p + 1) % MEM_SIZE] - 1] = r1 ^ r2;
	player->pos += p + 2;
	check_carry(player, r1, r2, flag);
}
